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


@interface NSURLConnection : NSObject <NSURLHandleClient>
{
	NSURLHandle *_handle;
	NSMutableData *_loadedData;
	id *_delegate;
}

+ (NSURLConnection *) connectionWithRequest:(NSURLRequest *) request delegate:(id)delegate;

- (id) initWithRequest:(NSURLRequest *) request delegate:(id) delegate;
- (void) cancel;

- (NSURLRequest *) requestWithURL:(NSURL *) url;	// create request

@end
