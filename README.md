<p align="center" >
<img src="https://github.com/highcharts/highcharts-ios/blob/master/Images/logo.png" alt="Highcharts" title="Highcharts">
</p>

[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

[Highcharts iOS](https://www.highcharts.com/products/ios/) is a delightful wrapper of HighchartsJS for iOS.

The most popular, robust and battle-tested JavaScript Charting library is now available for iOS with our new Objective-C wrapper. Get gorgeous, multi-touch charts with minimal effort.

## Documentation

Access the full [API documentation](http://api.highcharts.com/highcharts-ios/) here.

# HOWTO

Here we present how to create basic chart and place it in your project.


## What we need to do

  - Prepare your project for Highcharts
  - Create chart view and place it in your view
  - Create chart options and add them to your chart view
  - Run your app and enjoy!


## Preparing your project

- First of all download Highcharts framework from here: [Highcharts](https://github.com/highcharts/highcharts-ios) 
or by using Cocoapods by adding 
    ```
    pod 'Highcharts', '~> 8.0.0'
    ```
    to your Podfile
    
    or Carthage by adding
    ```
    github "https://github.com/highcharts/highcharts-ios" >= 8.0.0
    ```
    to your Cartfile. Please be advised that this is a development framework which contains intel architectures. 
    In order to submit a build to the app store you either need to remove those architectures using lipo,
    attach the version found in "release" folder manually or use CocoaPods.
    
    
- Now add Highcharts to your project by simply copying it to your project to folder **Frameworks** (create it if necessary) and remeber to check "**Copy items if needed**" option

![alt text](https://github.com/highcharts/highcharts-ios/blob/master/Images/3.png "Files")

- Click on **finish**

![alt text](https://github.com/highcharts/highcharts-ios/blob/master/Images/2.png "Copy")

- Then go to your project settings and add Highcharts to **Embedded Binaries**

![alt text](https://github.com/highcharts/highcharts-ios/blob/master/Images/1.png "Embedded")

- If your project is leveraging Xcode UI testing, make sure you add the Highcharts framework to Embedded Binaries for the UITests target as well as the main project target

You are now set to use Highcharts!

Please note when linking manually that binary framework in the 'release' directory is designed to allow uploads to the AppStore. Therefore it does not allow running on iOS Simulator.
In order to use simulator, download the repository and use framework that can be found in the 'development' directory.
Cocoapods solve this problem automatically - they introduce a stripping script for AppStore uploads.

## Using Highcharts (demo app)

##### Set AppDelegate

In your **AppDelegate.m** import Highcharts at the top

```objc
#import <Highcharts/Highcharts.h>
```
Add this line to your **application:didFinishLaunchingWithOptions**

```objc
[HIChartView preload];
```
#### Add HIChartView to your View Controller
In your View Controller .m file add
```objc
#import <Highcharts/Highcharts.h>
```
Then change
```objc
@interface ViewController ()
@end
```
To
```objc
@interface ViewController ()
@property (strong, nonatomic) HIChartView *chartView;
@end
```
#### Creating chart
Let's start with creating simple chart!

For the purpose of this tutorial, we will create a simple column chart using random data.

In **viewDidLoad** add following lines
```objc
self.chartView = [[HIChartView alloc] initWithFrame:CGRectMake(self.view.bounds.origin.x, self.view.bounds.origin.y + 20, self.view.bounds.size.width, 300.0f)];
```
This will create our chartView with defined origin and size.

Done!
Now let's create a chart.

The heart of a chart is **HIOptions** class which contains all the information needed to present it. Some of the options there are optional, some are not (see demo app [HighFit](https://github.com/highcharts/highcharts-ios/tree/master/Example/HighFit) provided by Highcharts). 

Create instance of **HIOptions** class
```objc
HIOptions *options = [[HIOptions alloc]init];
```
Now we need to add the options that our chart requires to be presented. Let's start with **chart type**. To do so, create HIChart class object and set its type to "column"
```objc
HIChart *chart = [[HIChart alloc]init];
chart.type = @"column";
```
Add this object to your **options**
```objc
options.chart = chart;
```
Then let's give our chart a name (title) and also add it to **options**
```objc
HITitle *title = [[HITitle alloc]init];
title.text = @"Demo chart";

options.title = title;
```
Now we need to add some data (in this tutorial it will be some random set of numbers). Since we are creating a **column** chart, we need to use **HIColumn** data series
```objc
HIColumn *series = [[HIColumn alloc]init];
```
To add data, just create array of our data objects
```objc
series.data = @[@49.9, @71.5, @106.4, @129.2, @144, @176, @135.6, @148.5, @216.4, @194.1, @95.6, @54.4];
```
Since options can store multiple series, we need to add our series as one-element-array
```objc
options.series = @[series];
```
And at last add our **options** to the chartView
```objc
self.chartView.options = options;
```

Don't forget to add chartView as subview to your View Controller's view! At the end add
```objc
[self.view addSubview:self.chartView];
```
That's it! We are now set to run our application!
Your View Controller .m file should look like this
```objc
#import "ViewController.h"
#import <Highcharts/Highcharts.h>

@interface ViewController ()
@property (strong, nonatomic) HIChartView *chartView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.chartView = [[HIChartView alloc] initWithFrame:CGRectMake(self.view.bounds.origin.x, self.view.bounds.origin.y + 20, self.view.bounds.size.width, 300.0f)];
    
    HIOptions *options = [[HIOptions alloc]init];
    
    HIChart *chart = [[HIChart alloc]init];
    chart.type = @"column";
    options.chart = chart;
    
    HITitle *title = [[HITitle alloc]init];
    title.text = @"Demo chart";
    options.title = title;
    
    HIColumn *series = [[HIColumn alloc]init];
    series.data = @[@49.9, @71.5, @106.4, @129.2, @144, @176, @135.6, @148.5, @216.4, @194.1, @95.6, @54.4];
    options.series = @[series];
    self.chartView.options = options;
    
    [self.view addSubview:self.chartView];
}

@end
```

## ***Press "Run" in XCode.***
#### For more complex solutions see demo app [HighFit](https://github.com/highcharts/highcharts-ios/tree/master/Example/HighFit) provided by Highcharts or read the following [documentation](http://api.highcharts.com/highcharts-ios/)!

# Additional info
#### Additional modules

In case of enabling additional module, add it to `plugins` of `HIChartView` object before assign your chart options, e.g.

```objc
self.chartView.plugins = @[ @"annotations" ];
...
self.chartView.options = options;
```

#### HIColor example
Highcharts iOS wrapper provides its own colors implementation. As you can notice, some options are of `HIColor` type. You can instantiate the desired color in few ways which are described in the [API documentation](https://api.highcharts.com/ios/highcharts/). In here, we will show the most complex case which is gradient usage. For example, you can instantiate a color for chart background:
```objc
HIChart *chart = [[HIChart alloc]init];
chart.backgroundColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @300 } stops:@[
                                                                                                                            @[@0, @"rgb(102, 153, 161)"],
                                                                                                                            @[@1, @"rgb(128, 135, 232)"]
                                                                                                                        ]];
```

#### HIFunction example
Thanks to Highcharts iOS wrapper you can now assign native iOS closures to events for specific chart elements. We will show you a small taste of such usage. For these purpose we will let appear a simple alert with point coordinates when it's clicked but keep in mind that you can achieve much more with `HIFunction` mechanism! 

First of all, you need to create a `plotOptions` object for your series type:
```objc
HIPlotOptions *plotOptions = [[HIPlotOptions alloc] init];
plotOptions.series = [[HISeries alloc] init];
```
Now, you can refer to the point event and add on click closure like this:
```objc
plotOptions.series.point = [[HIPoint alloc] init];
plotOptions.series.point.events = [[HIEvents alloc] init];
    
HIClosure closure = ^(HIChartContext *context) {
    NSString *alertMessage = [NSString stringWithFormat:@"Category: %@, value: %@", [context getProperty:@"this.category"], [context getProperty:@"this.y"]];
        
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:alertMessage preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * action) {}];
    [alert addAction:defaultAction];
    [self presentViewController:alert animated:YES completion:nil];
};
    
plotOptions.series.point.events.click = [[HIFunction alloc] initWithClosure:closure properties:@[@"this.category", @"this.y"]];
```
As you can see in the above code snippet first argument of the `HIFunction` is the actual closure. Second argument is simple string array of chart elements. We need to put them here to let wrapper pull them for us during `HIFunction` instantiation. Thanks to this, we can refer to these elements corresponding values by `getProperty:` method. You can pull any data from chart like this. Depending on the current needs you can just run some code, withdraw data from chart, return a String to the chart (e.g. in HITooltip formatter) and even put pure Javascript function in the constructor in the String format. For more information feel free to check the [API documentation](https://api.highcharts.com/ios/highcharts/).

#### Custom fonts
Highcharts iOS wrapper allows you to add custom fonts. If you have your own font and want to use that in your chart, follow next steps:

- Add a font file to your project. Select **File** -> **Add Files to “Your Project Name”** from the menu bar or drag and drop the file into your Xcode project, check **Copy items if needed** option and add the font to your app target. 

![alt text](https://github.com/highcharts/highcharts-ios/blob/master/Images/4.png "AddFont")

![alt text](https://github.com/highcharts/highcharts-ios/blob/master/Images/5.png "Fonts")

- Add your font to `HIChartView`. To do this, firstly, you need to get an absolute path pointing to the location of the font and then call `addFont:` method:
```objc
NSString *fontPath = [[NSBundle mainBundle] pathForResource:@"Windsong" ofType:@"ttf"];
[HIChartView addFont:fontPath];
```

So, now you can use a custom font in your chart. For example, let's change the chart title font. You only need to create a style object for the title and set its font family to the font file name:
```objc
title.style = [[HICSSObject alloc] init];
title.style.fontFamily = @"Windsong";
```