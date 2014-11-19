//
//  SoundView.h
//  Sound
//
//  Created by wang3140@hotmail.com on 14-7-29.
//  Copyright (c) 2014年 RTChatTeam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

enum SoundOpState {
    SoundOpReady,
    SoundOpRecording,
    SoundOpPlaying,
};

@interface SoundObject : NSObject <AVAudioPlayerDelegate,AVAudioSessionDelegate>

@property (nonatomic) enum SoundOpState opstate;
@property (nonatomic, strong) AVAudioPlayer *player;
@property (nonatomic, strong) AVAudioRecorder* recorder;
@property (nonatomic) NSInteger  current_record_labelid;
@property (nonatomic, strong) NSString*    current_recordedFile_caf;
@property (nonatomic, strong) NSString*    current_recordedFile_mp3;
@property (nonatomic, strong) NSMutableDictionary*  recordFileDic;

+ (SoundObject *) sharedInstance;

/// 开始录音
-(BOOL)beginRecord:(NSInteger)labelid;

/// 停止录音
-(NSInteger)stopRecord:(NSString**)filename;

/// 开始播放内存中的音频
-(BOOL)beginPlay:(NSData*)data;

/// 停止当前播放
-(void)stopPlay;

/// 是否已经下载过对应标签的文件
-(NSString*)haveLabelId:(NSInteger)labelid;

/// 根据标签ID获取录音时长
-(NSInteger)getRecordDuration:(NSInteger)labelid;

/// 播放本地文件
-(void)beginPlayLocalFile:(NSString*)filename;

/// 保存内存录音数据为本地磁盘文件
-(BOOL)saveCacheToDiskFile:(NSInteger)labelid data:(NSData*)data;

/// 清除缓冲的录音文件
-(void)clearAllCachedFile;

@end
