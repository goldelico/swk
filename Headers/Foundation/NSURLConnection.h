//
//  NSURLConnection.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSURLResponse.h>

@class NSURLAuthenticationChallenge;
@class NSCachedURLResponse;

@interface NSURLConnection : NSObject
{
	id _delegate;
}

+ (BOOL) canHandleRequest:(NSURLRequest *) request;
+ (NSURLConnection *) connectionWithRequest:(NSURLRequest *) request delegate:(id) delegate;
+ (NSData *) sendSynchronousRequest:(NSURLRequest *) request returningResponse:(NSURLResponse **) response error:(NSError **) error;

- (id) initWithRequest:(NSURLRequest *) request delegate:(id) delegate;
- (void) cancel;

@end

@interface NSObject (NSURLConnectionDelegate)

- (void) connection:(NSURLConnection *) conn didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *) challenge;
- (void) connection:(NSURLConnection *) conn didFailWithError:(NSError *) error;
- (void) connection:(NSURLConnection *) conn didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *) challenge;
- (void) connection:(NSURLConnection *) conn didReceiveData:(NSData *) data;
- (void) connection:(NSURLConnection *) conn didReceiveResponse:(NSURLResponse *) resp;
- (NSCachedURLResponse *) connection:(NSURLConnection *) conn willCacheResponse:(NSCachedURLResponse *) resp;
- (NSURLRequest *) connection:(NSURLConnection *) conn willSendRequest:(NSURLRequest *) req redirectResponse:(NSURLResponse *) resp;
- (void) connectionDidFinishLoading:(NSURLConnection *) conn;

@end