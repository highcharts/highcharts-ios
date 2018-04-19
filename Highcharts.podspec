Pod::Spec.new do |s|


  s.name         = "Highcharts"
  s.version      = "6.1.0"
  s.summary      = "Powerful, vast charting library"

  s.description  = <<-DESC
                   Objective-C wrapper for the popular Highcharts charting library. Convenient class infrastructure allows one to quickly embed charts in iOS apps, written in Objective-C or Swift. Supports dozens of responsive chart types, with a simple, yet powerful API. Easy to setup. See our Demo App for details.                    
                   DESC

   s.homepage     = "https://github.com/highcharts/highcharts-ios"
   s.license   =  { :type =>'Custom', :file => "LICENSE" }
   
   s.author             = "Highsoft"
   s.source       = { :git => "https://github.com/highcharts/highcharts-ios.git", :tag => "v6.1.0" }
   s.ios.deployment_target = '8.0'

   
   s.ios.vendored_frameworks = 'development/Highcharts.framework'
 
end