//
//  WebDataSource.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/NSURLConnection.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSURLResponse.h>
#import <WebKit/WebDocument.h>
@class WebArchive;
@class WebFrame;
@class WebResource;

@interface WebDataSource : NSObject
// does this object simply describe a data source or does it load???
// if yes, we need (private) methods to start/stop loading - otherwise WebFrame must do the loading
{
	NSURLConnection *_connection;	// our connection
	NSURLRequest *_initial;
	NSMutableURLRequest *_request;
	NSURLResponse *_response;
	NSMutableData *_loadedData;
	NSMutableArray *_subresources;
	BOOL _isLoading;	// initially set, reset by being the delegate of an NSURLCOnnection when done
}

- (void) addSubresource:(WebResource *) res;
- (NSData *) data;
- (NSURLRequest *) initialRequest;
- (id) initWithRequest:(NSURLRequest *) request;
- (BOOL) isLoading;
- (WebResource *) mainResource;
- (NSString *) pageTitle;
- (id <WebDocumentRepresentation>) representation;
- (NSMutableURLRequest *) request;
- (NSURLResponse *) response;
- (NSArray *) subresources;
- (WebResource *) subresourceForURL:(NSURL *) url;
- (NSString *) textEncodingName;
- (NSURL *) unreachableURL;
- (WebArchive *) webArchive;
- (WebFrame *) webFrame;

@end
