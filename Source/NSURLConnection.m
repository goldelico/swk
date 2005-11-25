//
//  NSURLConnection.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Foundation/NSURLConnection.h>

@interface _NSConcreteURLConnection : NSURLConnection <NSURLHandleClient>
{
	NSURLHandle *_handle;
	NSMutableData *_loadedData;
	// default implementation for HTTP protocol without using NSURLProtocol
	// probably we should reverse everything and base NSURLHandle on NSURLConnection later on
}

@end

@implementation NSURLConnection

+ (id) alloc;
{
	return [_NSConcreteURLConnection alloc];	// surrogate object that responds to NSURLHandleClient
}

@end

@implementation _NSConcreteURLConnection

#ifdef __mySTEP__

+ (BOOL) canHandleRequest:(NSURLRequest *) request;
{
	return [NSURLHandle canInitWithURL:[request URL]];
}

+ (NSURLConnection *) connectionWithRequest:(NSURLRequest *) request delegate:(id) delegate;
{
	return [[[self alloc] initWithRequest:request delegate:delegate] autorelease];
}

+ (NSData *) sendSynchronousRequest:(NSURLRequest *) request returningResponse:(NSURLResponse **) response error:(NSError **) error;
{
	NIMP;
}

- (id) initWithRequest:(NSURLRequest *) request delegate:(id) delegate;
{
	self=[super init];
	if(self)
		{
		_delegate=delegate;
		_handle=[[NSURLHandle cachedHandleForURL:[request URL]] retain];
		}
	return self;
}

- (void) dealloc;
{
	[_handle cancelLoadInBackground];
	[_handle release];
	[super dealloc];
}

- (void) cancel;
{ // stop loading
	[_handle cancelLoadInBackground];
}

// notification _handler

- (void) URLhandleResourceDidBeginLoading:(NSURLHandle *)sender
{
	_loadedData=[[NSMutableData dataWithCapacity:1000] retain];  // create data container
}

- (void) URLhandleResourceDidCancelLoading:(NSURLHandle *)sender
{
	[_handle removeClient:self];	// no longer receive notifications - may be cached!
	[_handle release];
	_handle=nil;
	[_loadedData release];	// release previous data
}

- (void) URLhandleResourceDidFinishLoading:(NSURLHandle *)sender
{
	[_handle removeClient:self];	// no longer receive notifications - may be cached!
	[_handle release];
	_handle=nil;
	[_loadedData release];	// release previous data
}

- (void) URLhandle:(NSURLHandle *)sender resourceDataDidBecomeAvailable:(NSData *)newBytes
{
	//	NSLog(@"new data (%u)", [newBytes length]);
	[_loadedData appendData:newBytes];
	// use the basic rendering engine
	// find <title>...</title> in loaded data and set window title
}

- (void) URLhandle:(NSURLHandle *)sender resourceDidFailLoadingWithReason:(NSString *)reason
{
	// notify error
	[self URLhandleResourceDidFinishLoading:sender];
}

#endif

@end
