//
//  NSXMLParser.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Tue Oct 05 2004.
//  Copyright (c) 2004 DSITRI.
//
//  H.N.Schaller, Dec 2005 - API revised to be compatible to 10.4
//
//  This file is part of the mySTEP Library and is provided
//  under the terms of the GNU Library General Public License.
//

#ifndef mySTEP_NSXMLPARSER_H
#define mySTEP_NSXMLPARSER_H

#import "Foundation/Foundation.h"

#ifndef __WebKit__	// may be #included in WebKit sources where this is already declared

extern NSString *const NSXMLParserErrorDomain;

typedef enum _NSXMLParserError
{
	NSXMLParserInternalError=1,
	NSXMLParserOutOfMemoryError,
	NSXMLParserDocumentStartError,
	NSXMLParserEmptyDocumentError,
	NSXMLParserPrematureDocumentEndError,
	NSXMLParserInvalidHexCharacterRefError,
	NSXMLParserInvalidDecimalCharacterRefError,
	NSXMLParserInvalidCharacterRefError,
	NSXMLParserInvalidCharacterError,
	NSXMLParserCharacterRefAtEOFError,
	NSXMLParserCharacterRefInPrologError,
	NSXMLParserCharacterRefInEpilogError,
	NSXMLParserCharacterRefInDTDError,
	NSXMLParserEntityRefAtEOFError,
	NSXMLParserEntityRefInPrologError,
	NSXMLParserEntityRefInEpilogError,
	NSXMLParserEntityRefInDTDError,
	NSXMLParserParsedEntityRefAtEOFError,
	NSXMLParserParsedEntityRefInPrologError,
	NSXMLParserParsedEntityRefInEpilogError,
	NSXMLParserParsedEntityRefInInternalSubsetError,
	NSXMLParserEntityReferenceWithoutNameError,
	NSXMLParserEntityReferenceMissingSemiError,
	NSXMLParserParsedEntityRefNoNameError,
	NSXMLParserParsedEntityRefMissingSemiError,
	NSXMLParserUndeclaredEntityError,
	NSXMLParserUnparsedEntityError,
	NSXMLParserEntityIsExternalError,
	NSXMLParserEntityIsParameterError,
	NSXMLParserUnknownEncodingError,
	NSXMLParserEncodingNotSupportedError,
	NSXMLParserStringNotStartedError,
	NSXMLParserStringNotClosedError,
	NSXMLParserNamespaceDeclarationError,
	NSXMLParserEntityNotStartedError,
	NSXMLParserEntityNotFinishedError,
	NSXMLParserLessThanSymbolInAttributeError,
	NSXMLParserAttributeNotStartedError,
	NSXMLParserAttributeNotFinishedError,
	NSXMLParserAttributeHasNoValueError,
	NSXMLParserAttributeRedefinedError,
	NSXMLParserLiteralNotStartedError,
	NSXMLParserLiteralNotFinishedError,
	NSXMLParserCommentNotFinishedError,
	NSXMLParserProcessingInstructionNotStartedError,
	NSXMLParserProcessingInstructionNotFinishedError,
	NSXMLParserNotationNotStartedError,
	NSXMLParserNotationNotFinishedError,
	NSXMLParserAttributeListNotStartedError,
	NSXMLParserAttributeListNotFinishedError,
	NSXMLParserMixedContentDeclNotStartedError,
	NSXMLParserMixedContentDeclNotFinishedError,
	NSXMLParserElementContentDeclNotStartedError,
	NSXMLParserElementContentDeclNotFinishedError,
	NSXMLParserXMLDeclNotStartedError,
	NSXMLParserXMLDeclNotFinishedError,
	NSXMLParserConditionalSectionNotStartedError,
	NSXMLParserConditionalSectionNotFinishedError,
	NSXMLParserExternalSubsetNotFinishedError,
	NSXMLParserDOCTYPEDeclNotFinishedError,
	NSXMLParserMisplacedCDATAEndStringError,
	NSXMLParserCDATANotFinishedError,
	NSXMLParserMisplacedXMLDeclarationError,
	NSXMLParserSpaceRequiredError,
	NSXMLParserSeparatorRequiredError,
	NSXMLParserNMTOKENRequiredError,
	NSXMLParserNAMERequiredError,
	NSXMLParserPCDATARequiredError,
	NSXMLParserURIRequiredError,
	NSXMLParserPublicIdentifierRequiredError,
	NSXMLParserLTRequiredError,
	NSXMLParserGTRequiredError,
	NSXMLParserLTSlashRequiredError,
	NSXMLParserEqualExpectedError,
	NSXMLParserTagNameMismatchError,
	NSXMLParserUnfinishedTagError,
	NSXMLParserStandaloneValueError,
	NSXMLParserInvalidEncodingNameError,
	NSXMLParserCommentContainsDoubleHyphenError,
	NSXMLParserInvalidEncodingError,
	NSXMLParserExternalStandaloneEntityError,
	NSXMLParserInvalidConditionalSectionError,
	NSXMLParserEntityValueRequiredError,
	NSXMLParserNotWellBalancedError,
	NSXMLParserExtraContentError,
	NSXMLParserInvalidCharacterInEntityError,
	NSXMLParserParsedEntityRefInInternalError,
	NSXMLParserEntityRefLoopError,
	NSXMLParserEntityBoundaryError,
	NSXMLParserInvalidURIError,
	NSXMLParserURIFragmentError,
	NSXMLParserNoDTDError,
	NSXMLParserDelegateAbortedParseError=512
} NSXMLParserError;

#endif

@interface NSXMLParser : NSObject
{
	id delegate;					// the current delegate (not retained)
	NSMutableArray *tagPath;		// hierarchy of tags
	NSError *error;
	const unsigned char *cp;		// character pointer
	const unsigned char *cend;		// end of data
	int line;						// current line (counts from 0)
	int column;						// current column (counts from 0)
	NSStringEncoding encoding;
	BOOL abort;						// abort parse loop
	BOOL shouldProcessNamespaces;
	BOOL shouldReportNamespacePrefixes;
	BOOL shouldResolveExternalEntities;
	BOOL acceptHTML;				// be lazy with bad tag nesting and be not case sensitive
}

- (void) abortParsing;
- (int) columnNumber;
- (id) delegate;
- (id) initWithContentsOfURL:(NSURL *) url;
- (id) initWithData:(NSData *) str;
- (int) lineNumber;
- (BOOL) parse;
- (NSError *) parserError;
- (NSString *) publicID;
- (void) setDelegate:(id) del;
- (void) setShouldProcessNamespaces:(BOOL) flag;
- (void) setShouldReportNamespacePrefixes:(BOOL) flag;
- (void) setShouldResolveExternalEntities:(BOOL) flag;
- (BOOL) shouldProcessNamespaces;
- (BOOL) shouldReportNamespacePrefixes;
- (BOOL) shouldResolveExternalEntities;
- (NSString *) systemID;

@end

@interface NSObject (NSXMLParserDelegate)

- (void) parser:(NSXMLParser *) parser didEndElement:(NSString *) tag namespaceURI:(NSString *) URI qualifiedName:(NSString *) name;
- (void) parser:(NSXMLParser *) parser didEndMappingPrefix:(NSString *) prefix;
- (void) parser:(NSXMLParser *) parser didStartElement:(NSString *) tag namespaceURI:(NSString *) URI qualifiedName:(NSString *) name attributes:(NSDictionary *) attributes;
- (void) parser:(NSXMLParser *) parser didStartMappingPrefix:(NSString *)prefix toURI:(NSString *) URI;
- (void) parser:(NSXMLParser *) parser foundAttributeDeclarationWithName:(NSString *) name forElement:(NSString *) element type:(NSString *) type defaultValue:(NSString *) val;
- (void) parser:(NSXMLParser *) parser foundCDATA:(NSData *) CDATABlock;
- (void) parser:(NSXMLParser *) parser foundCharacters:(NSString *) string;
- (void) parser:(NSXMLParser *) parser foundComment:(NSString *) comment;
- (void) parser:(NSXMLParser *) parser foundElementDeclarationWithName:(NSString *) element model:(NSString *) model;
- (void) parser:(NSXMLParser *) parser foundExternalEntityDeclarationWithName:(NSString *) entity publicID:(NSString *) pub systemID:(NSString *) sys;
- (void) parser:(NSXMLParser *) parser foundIgnorableWhitespace:(NSString *) whitespaceString;
- (void) parser:(NSXMLParser *) parser foundInternalEntityDeclarationWithName:(NSString *) name value:(NSString *) val;
- (void) parser:(NSXMLParser *) parser foundNotationDeclarationWithName:(NSString *) name publicID:(NSString *) pub systemID:(NSString *) sys;
- (void) parser:(NSXMLParser *) parser foundProcessingInstructionWithTarget:(NSString *) target data:(NSString *) data;
- (void) parser:(NSXMLParser *) parser foundUnparsedEntityDeclarationWithName:(NSString *) name publicID:(NSString *) pub systemID:(NSString *) sys notationName:(NSString *) notation;
- (void) parser:(NSXMLParser *) parser parseErrorOccurred:(NSError *) parseError;
- (NSData *) parser:(NSXMLParser *) parser resolveExternalEntityName:(NSString *) entity systemID:(NSString *) sys;
- (void) parser:(NSXMLParser *) parser validationErrorOccurred:(NSError *) error;
- (void) parserDidEndDocument:(NSXMLParser *) parser;
- (void) parserDidStartDocument:(NSXMLParser *) parser;

@end

#endif mySTEP_NSXMLPARSER_H
