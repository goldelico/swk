//
//  WebDataSource.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebDataSource.h>

@implementation WebDataSource

- (id) initWithRequest:(NSURLRequest *) request;
{
    self = [super init];
    if (self)
		{ // If an error occurs here, send a [self release] message and return nil.
		_initial=[request retain];
		_request=[_initial mutableCopy];
		_connection=[[NSURLConnection connectionWithRequest:_request delegate:self] retain];
		_isLoading=YES;
		_subresources=[[NSMutableArray alloc] initWithCapacity:20];
		NSLog(@"load url %@", [[_initial URL] absoluteString]);
		}
    return self;
}

- (void) dealloc;
{
	[_connection cancel];	// cancel any pending actions 
	[_connection release];
	[_initial release];
	[_request release];
	[_loadedData release];
	[_subresources release];
	[super dealloc];
}

- (void) stopLoading;
{ // stop loading
	[_connection cancel];
	_isLoading=NO;
}

- (BOOL) isLoading; { return _isLoading; }

- (void) addSubresource:(WebResource *) res; { [_subresources addObject:res]; }

- (NSData *) data; { return _loadedData; }

- (NSURLRequest *) initialRequest; { return _initial; }

- (WebResource *) mainResource; { NIMP; }

- (NSString *) pageTitle;
{
	// extract from <title> tag
	return @"Page Title";
}
	
- (id <WebDocumentRepresentation>) representation;
{
	return NIMP;
}

- (NSMutableURLRequest *) request; { return _request; }

- (NSURLResponse *) response; { return _response; }

- (NSArray *) subresources; { return _subresources; }

- (WebResource *) subresourceForURL:(NSURL *) url;
{
	return NIMP;
}

- (NSString *) textEncodingName; { return @"Default"; }

- (NSURL *) unreachableURL; { return NIMP; }

- (WebArchive *) webArchive;
{
	// parse data into webArchive
	return NIMP;
}

- (WebFrame *) webFrame;
{
	// parse data into WebFrame
	return nil;
}

@end
