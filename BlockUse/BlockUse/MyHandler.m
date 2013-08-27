//
//  MyHandler.m
//  BlockUse
//
//  Created by 紫冬 on 13-8-27.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

#import "MyHandler.h"

@implementation MyHandler

-(void)handle:(void(^)(void))task
{
    NSLog(@"开始处理");
    
    task();
}

@end
