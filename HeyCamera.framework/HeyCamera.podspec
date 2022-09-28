Pod::Spec.new do |s|
  s.name         = "HeyCamera"
  s.version      = "1.1.6"
  s.summary      = "HeyHome SDK for iOS at CocoaPods."
  s.description  = "HeyHome SDK for iOS at CocoaPods."

  s.homepage     = "https://gitee.com/eafy/HeyCamera"
  s.license      = { :type => "Apache License 2.0"}
  s.author       = { "Eafy" => "lizhijian_21@163.com" }
  s.requires_arc = true
  s.platform   = :ios, '11.0'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.libraries = 'c++','z','bz2','iconv'
  s.frameworks = 'CoreMedia','VideoToolbox','AudioToolbox', 'AVFoundation','OpenGLES','GLKit','CoreImage'
  s.dependency 'ZJMediaPlayer', '~> 1.4.7-beta'
  s.dependency 'MJExtension'
  s.dependency 'AFNetworking'
  s.dependency 'Reachability'
  s.dependency 'CocoaAsyncSocket'
  s.dependency 'ZJBaseUtils', '~> 1.3.0'
  
  s.vendored_libraries = 'Libs/**/*.a'
  s.resources = 'Libs/**/*.a'

  s.source       = { :git => "https://gitee.com/eafy/HeyCamera.git", :tag => "v#{s.version}"}
  s.source_files  = "HeyCamera/**/*.{h,m,mm,c,hpp,cpp}", "Libs/**/*.{h,m,mm,c,hpp,cpp}"
  s.public_header_files = "HeyCamera/HeyCamera.h","HeyCamera/HHCamera.h","HeyCamera/HHCameraDelegate.h", "HeyCamera/CmdManager/HHCmdSendManager.h", "HeyCamera/HHDeviceConfig.h", "HeyCamera/HHErrno.h", "HeyCamera/Other/HHFrameInfo.h", "HeyCamera/Other/HHMonitor.h"

end

#校验指令
#pod lib lint HeyCamera.podspec --verbose --allow-warnings --use-libraries
#打包指令
#pod package HeyCamera.podspec --force --no-mangle --exclude-deps --verbose
