//
//  WebFrameView.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class WebFrame;

@interface WebFrameView : NSView {
	NSScrollView *_view;
	BOOL _allowsScrolling;
}

- (id) _initWithFrame:(NSRect) frame documentView:(NSView *) docview webFrame:(WebFrame *) webFrame;

- (BOOL) allowsScrolling;
- (WebFrame *) webFrame;
- (NSView *) documentView;
- (void) setAllowsScrolling:(BOOL) flag;

@end
