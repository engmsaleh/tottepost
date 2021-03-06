//
//  UVSubdomain.h
//  UserVoice
//
//  Created by Scott Rutherford on 28/05/2010.
//  Copyright 2010 UserVoice Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UVBaseModel.h"

@interface UVSubdomain : UVBaseModel {
	NSString *name;
	NSString *host;
	NSString *key;
	NSArray *statuses;
	NSInteger subdomainId;
}

@property (assign) NSInteger subdomainId;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *host;
@property (nonatomic, retain) NSString *key;
@property (nonatomic, retain) NSArray *statuses;
 
@end
