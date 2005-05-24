//
//  WebDataSource.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/NSURLRequest.h>
@class WebFrame;

@interface WebDataSource : NSObject <NSURLHandleClient> // does this object simply describe a data source or does it load???
// if yes, we need (private) methods to start/stop loading - otherwise WebFrame must do the loading
{
	NSURLRequest *request;
	NSURLHandle *handle;
	NSMutableData *loadedData;
}

- (NSData *) data;
- (NSURLRequest *) initialRequest;
- (id) initWithRequest:(NSURLRequest *) request;
- (BOOL) isLoading;
- (NSString *) pageTitle;
// - (id <WebDocumentRepresentation>) representation;
- (NSMutableURLRequest *) request;
// - (WebResponse *) response;  ??? not documented in WebKit
- (NSString *) textEncodingName;
- (WebFrame *) webFrame;

@end
