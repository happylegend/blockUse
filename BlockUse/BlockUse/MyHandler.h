//
//  MyHandler.h
//  BlockUse
//
//  Created by 紫冬 on 13-8-27.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

#import <Foundation/Foundation.h>

//用来测试回调，也即是通过task块，来操作宿主类的数据
@interface MyHandler : NSObject

-(void)handle:(void(^)(void))task;

@end
