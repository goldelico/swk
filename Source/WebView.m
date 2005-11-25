//
//  WebView.m
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <WebKit/WebView.h>
#import <WebKit/WebFrame.h>

@implementation WebView

- (id) initWithFrame:(NSRect) frame;
{
	self=[super initWithFrame:frame];
	if(self)
		{
		// add _mainFrame
		}
	return self;
}

- (WebFrame *) mainFrame;   { return _mainFrame; }
- (void) setUIDelegate:(id) uid; { _uiDelegate=uid; }
- (void) setGroupName:(NSString *) str; { }
- (void) setMaintainsBackForwardList:(BOOL) flag; { }
- (void) setCustomUserAgent:(NSString *) agent; { }
- (void) setApplicationNameForUserAgent:(NSString *) name; { }

- (BOOL) canGoBack; { return NO; }
- (BOOL) canGoForward; { return NO; }

- (IBAction) takeStringURLFrom:(id) sender;
{
	NSURL *u=[NSURL URLWithString:[sender stringValue]];
	[_mainFrame loadRequest:[NSURLRequest requestWithURL:u]];
}

- (double) estimatedProgress; { return 0.0; }

- (IBAction) reload:(id) sender;
{
	[_mainFrame reload];
}

- (IBAction) stopLoading:(id) sender;
{
	[_mainFrame stopLoading];
}

#ifdef __mySTEP__

- (IBAction) goBack:(id) sender; { NIMP; }
- (IBAction) goForward:(id) sender; { NIMP; }
- (IBAction) makeTextLarger:(id) sender; { NIMP; }
- (IBAction) makeTextSmaller:(id) sender; { NIMP; }

#endif

@end
