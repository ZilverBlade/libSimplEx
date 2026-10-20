#pragma once

#include <SimplEx/Platform.h>

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct SpxGrammar_t* SpxGrammar;
    typedef struct SpxParser_t* SpxParser;

    struct SpxGrammarConfig_t {

    };

    struct SpxParseTreeNode_t {
        int nodeId;
        char token;

        int left;
        int right;
    };

    struct SpxSyntaxError_t {
        const char* message;
        int line;
        int col;
        char c;
    };

    struct SpxParseError_t {
        const char* message;
        int line;
        int col;
        char c;
    };

    ZB_SPX_API int SpxVersion(void);

    ZB_SPX_API SpxGrammar SpxGrammar_Create(struct SpxParserConfig_t* pConfig);
    ZB_SPX_API void SpxGrammar_Destroy(SpxGrammar grammar);

    ZB_SPX_API void SpxGrammar_RegisterOperator(SpxGrammar grammar, char token, int precendence);

    // Parser context
    ZB_SPX_API SpxParser SpxParser_Create(SpxGrammar grammar);
    ZB_SPX_API void SpxParser_Destroy(SpxParser parser);

    ///< Tokenises the string
    ZB_SPX_API void SpxParser_ScanString(SpxParser parser, const char* szInput);

    ///< Constructs the parse tree
    ZB_SPX_API void SpxParser_ParseTokens(SpxParser parser);

    ///< Returns 0 if end is reached
    ZB_SPX_API int SpxParser_TraverseSyntaxErrors(SpxParser parser, void** ppIterator, struct SpxSyntaxError_t* pError);

    ///< Returns 0 if end is reached
    ZB_SPX_API int SpxParser_TraverseParseErrors(SpxParser parser, void** ppIterator, struct SpxParseError_t* pError);

    ///< Returns the parse tree
    ZB_SPX_API int SpxParser_TraverseTree(SpxParser parser, void** ppIterator, struct SpxParseTreeNode_t* pNode);

#ifdef __cplusplus
}
#endif