//
//  NSURLRequest.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSURLRequest : NSObject
{
	NSURL *_url;
}

+ (NSURLRequest *) requestWithURL:(NSURL *) url;	// create request
- (id) initWithURL:(NSURL *) url;
- (NSURL *) URL;

@end

@interface NSMutableURLRequest : NSURLRequest
{
}

- (void) setURL:(NSURL *) url;

@end