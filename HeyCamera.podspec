Pod::Spec.new do |s|
  s.name         = "HeyCamera"
  s.version      = "1.1.0"
  s.summary      = "Hey Camera SDK for iOS at CocoaPods."
  s.description  = "Hey Camera SDK for iOS at CocoaPods."

  s.homepage     = "https://github.com/Eafy/HeyCamera_CocoaPads"
  s.license      = { :type => "Apache License 2.0" }
  s.author       = { "Eafy" => "lizhijian_21@163.com" }
  s.platform     = :ios, "9.0"
  s.requires_arc = true
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.libraries = 'c++','z','bz2','iconv'
  s.frameworks = 'CoreMedia','VideoToolbox','AudioToolbox', 'AVFoundation','OpenGLES','GLKit','CoreImage'
  s.dependency 'ZJMediaPlayer'
  s.dependency 'MJExtension'
  s.dependency 'AFNetworking'
  s.dependency 'Reachability'
  s.dependency 'CocoaAsyncSocket'
  s.dependency 'ZJBaseUtils', '~> 1.1.8'
  
  s.source       = { :git => "https://github.com/Eafy/HeyCamera_CocoaPads.git", :tag => "v#{s.version}" }
  s.ios.vendored_frameworks = "HeyCamera.framework"
  s.vendored_libraries = 'HeyCamera.framework/**/*.a'

end

#推送命令
#pod trunk push HeyCamera.podspec --verbose --allow-warnings --use-libraries
