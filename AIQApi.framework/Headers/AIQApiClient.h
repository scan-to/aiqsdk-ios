//
//  AIQApiClient.h
//  AIQApi
//
//  Created by Khang Toh on 2/4/19.
//  Copyright © 2019 AIQ. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AIQBlocks.h"

@class AIQUser;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AIQApiHeaderOptionsGender) {
    AIQApiHeaderOptionsGenderUnspecified = 1,
    AIQApiHeaderOptionsGenderDefault = AIQApiHeaderOptionsGenderUnspecified,
    AIQApiHeaderOptionsGenderFemale,
    AIQApiHeaderOptionsGenderMale
};

@interface AIQApiClient : NSObject

+ (instancetype)sharedClient;

+ (instancetype)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret;

+ (instancetype)initializeWithAppKey:(NSString *)appKey appSecret:(NSString *)secret userId:(NSString *)userId;

// Optional user profile methods

+ (void)setUserAge:(NSInteger)age;

+ (void)setUserGender:(AIQApiHeaderOptionsGender)gender;

+ (void)setUserLocationLatitude:(float)lat longitude:(float)lng;

@end

@interface AIQApiClient (User)

- (void)updateUserProfile:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;


- (void)updateUserAvatar:(AIQUser *)user
               withImage:(UIImage *)image
          withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)retrieveUser:(NSString *)userToken withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)registerUser:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;

- (void)loginUser:(AIQUser *)user withCompletion:(AIQUserLoginCompletionBlock)completion;

- (void)logoutUser:(AIQUser *)user withCompletion:(AIQUserRequestCompletionBlock)completion;

@end

@interface AIQApiClient (Collections)

- (void)retrieveCollectionsWithCompletion:(AIQCollectionsCompletionBlock)completion;

@end

@interface AIQApiClient (ScanHistory)
- (void)retrieveScanHistoryWithCount:(NSInteger)count
                          withOffset:(NSInteger)offset
                    withCompletion:(AIQScanHistoryCompletionBlock)completion;

@end

@interface AIQApiClient (Scan)

- (void)scanWithUrl:(NSURL *)fileUrl
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithUrl:(NSURL *)fileUrl
     withCollection:(NSString *)collectionId
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithImage:(UIImage *)image
     withCompletion:(AIQScanCompletionBlock)completion;

- (void)scanWithImage:(UIImage *)image
       withCollection:(NSString *)collectionId
       withCompletion:(AIQScanCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
