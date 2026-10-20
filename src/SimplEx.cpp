#include <SimplEx/SimplEx.h>
#include <vector>
#include <string>
#include <unordered_map>

#define SPX_VERSION (0 << 24)|(1 << 16)|(0)

#ifdef _MSC_VER
#define SPX_UNUSED(x) _CRT_UNUSED(x)
#else
#define SPX_UNUSED(x) (void)(x)
#endif

namespace {
    namespace detail {
        static int IsWhiteSpace(char c) {
            return c == '\t' || c == '\r' || c == ' ';
        }

        static const int SPECIAL_PRIORITY = 0x7FFFFFFF;

        struct TokenLineInfo {
            int line;
            int col;
        };
    }
}

extern "C" {
    int SpxVersion() {
        return SPX_VERSION;
    }

    struct SpxGrammar_t {
        SpxGrammar_t() = default;
        std::unordered_map<char, int> tokens;
    };

    struct SpxParser_t {
        SpxParser_t() = default;
        SpxGrammar grammar;
        std::vector<SpxSyntaxError_t> errors;
        std::vector<char> tokenised;
        std::vector<detail::TokenLineInfo> lineInfos;
    };

    SpxGrammar SpxGrammar_Create(struct SpxParserConfig_t* pConfig) {
        SPX_UNUSED(pConfig);
        SpxGrammar_t* grammar = new SpxGrammar_t;
        grammar->tokens['('] = detail::SPECIAL_PRIORITY;
        grammar->tokens[')'] = detail::SPECIAL_PRIORITY;
        return grammar;
    }
    void SpxGrammar_Destroy(SpxGrammar grammar) {
        delete grammar;
    }

    void SpxGrammar_RegisterOperator(SpxGrammar grammar, char token, int precendence) {
        SPX_UNUSED(grammar);
        SPX_UNUSED(token);
        SPX_UNUSED(precendence);
    }


    SpxParser SpxParser_Create(SpxGrammar grammar) {
        SpxParser_t* parser = new SpxParser_t;
        parser->grammar = grammar;
        return parser;
    }
    void SpxParser_Destroy(SpxParser parser) {
        delete parser;
    }

    void SpxParser_ScanString(SpxParser parser, const char* szInput) {
        int line = 1;
        int col = 1;
        const auto& avail = parser->grammar->tokens;
        while (*szInput) {
            char token = *szInput++;
            if (token == '\n') {
                line++;
                col = 1;
                continue;
            }
            if (detail::IsWhiteSpace(token)) {
                continue;
            }
            auto it = avail.find(token);
            if (it == avail.end()) {
                struct SpxSyntaxError_t error;
                error.message = "Invalid token";
                error.line = line;
                error.col = col;
                error.c = token;
                parser->errors.push_back(error);
            }
            else {
                parser->tokenised.push_back(token);
                detail::TokenLineInfo lineInfo;
                lineInfo.line = line;
                lineInfo.col = col;
                parser->lineInfos.push_back(lineInfo);
            }
            col++;
        }
    }

    void SpxParser_ParseTokens(SpxParser parser) {
        for (auto it = parser->tokenised.cbegin(); it != parser->tokenised.end(); ++it) {

        }
    }


    int SpxParser_TraverseSyntaxErrors(SpxParser parser, void** ppIterator, struct SpxSyntaxError_t* pError) {
        SpxSyntaxError_t* begin = parser->errors.data();
        SpxSyntaxError_t* end = begin + parser->errors.size();
        if (*ppIterator == nullptr) {
            *ppIterator = begin;
        }
        if (*ppIterator == end) {
            return 0;
        }
        *pError = *(SpxSyntaxError_t*)*ppIterator;
        ++(SpxSyntaxError_t*&)*ppIterator;
        return 1;
    }

    int SpxParser_TraverseTree(SpxParser parser, void** ppIterator, struct SpxParseTreeNode_t* pNode) {
        SPX_UNUSED(parser);
        SPX_UNUSED(ppIterator);
        SPX_UNUSED(pNode);
        return 0;
    }

}