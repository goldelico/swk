//
//  NSURLResponse.h
//  mySTEP
//
//  Created by Dr. H. Nikolaus Schaller on Mon Jan 05 2004.
//  Copyright (c) 2004 DSITRI. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSURLResponse: NSObject
{
}

- (id) initWithURL:(NSURL *) URL MIMEType:(NSString *) MIMEType expectedContentLength:(int) length textEncodingName:(NSString *) name;
- (NSURL *) URL;

@end
