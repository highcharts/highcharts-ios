//
//  OptionsProvider.m
//  HighFit
//
//  License: www.highcharts.com/license
//  Copyright © 2016 Highsoft AS. All rights reserved.
//

#import "OptionsProvider.h"
#import <UIKit/UIKit.h>

@implementation OptionsProvider

//@[@0, @"rgb(98, 104, 166)"],
//@[@1, @"rgb(244, 153, 82)"]

+ (HIOptions*)provideOptionsForChartType:(NSDictionary*)options series:(NSArray*)series type:(NSString*)type;
{
    NSArray *categories = nil;
    
    id step = [NSNull null];
    
    if ([type isEqualToString:@"day"]) {
        categories = @[ @"12AM", @"", @"3AM", @"", @"6AM", @"", @"9AM", @"", @"12PM", @"", @"3PM", @"", @"6PM", @"", @"9PM", @"", @"12AM"];
        step = @1;
    }
    
    if ([type isEqualToString:@"week"]) {
        categories = @[@"Mon", @"Tue", @"Wed", @"Thu", @"Fri", @"Sat", @"Sun"];
    }
    
    if ([type isEqualToString:@"month"]) {
        categories = @[@1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15, @16, @17, @18, @19, @20, @21, @22, @23, @24, @25, @26, @27,@28, @29, @30];
    }
    
    if ([type isEqualToString:@"year"]) {
        categories = @[@"Jan", @"Feb", @"Mar", @"Apr", @"May", @"Jun", @"Jul", @"Aug", @"Sep", @"Oct", @"Nov", @"Dec"];
        step = @1;
    }
    
    if ([options[@"chartType"] isEqualToString:@"area"]) {
        
        HIOptions *hioptions = [[HIOptions alloc]init];
        
        HIChart *chart = [[HIChart alloc]init];
        chart.backgroundColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @300 } stops:@[
                                                                                                                                 @[@0, @"rgb(102, 153, 161)"],
                                                                                                                                 @[@1, @"rgb(128, 135, 232)"]
                                                                                                                                 ]];
        chart.borderRadius = @6;
        chart.type = options[@"chartType"];
        hioptions.chart = chart;
        
        HIExporting *exporting = [[HIExporting alloc]init];
        exporting.enabled = options[@"exporting"];
        hioptions.exporting = exporting;
        
        HINavigation *navigation = [[HINavigation alloc]init];
        navigation.buttonOptions = [[HIButtonOptions alloc]init];
        navigation.buttonOptions.symbolStroke = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.4];
        navigation.buttonOptions.theme = [[HITheme alloc] init];
        navigation.buttonOptions.theme.fill = @"rgba(0,0,0,0.0)";
        hioptions.navigation = navigation;
        
        HIPlotOptions *plotOptions = [[HIPlotOptions alloc]init];
        plotOptions.area = [[HIArea alloc]init];
        plotOptions.area.fillColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @150 } stops:@[
                                                                                                                                      @[@0, @"rgba(255,255,255, 0.75)"],
                                                                                                                                      @[@1, @"rgba(255,255,255, 0.02)"]
                                                                                                                                      ]];
        hioptions.plotOptions = plotOptions;
        
        HICredits *credits = [[HICredits alloc]init];
        credits.enabled = @NO;
        hioptions.credits = credits;
        
        HITitle *title = [[HITitle alloc]init];
        title.text = options[@"title"];
        title.align = @"left";
        title.style = [[HICSSObject alloc] init];
        title.style.fontFamily = @"Arial";
        title.style.fontSize = @"14px";
        title.style.color = @"rgba(255, 255, 255, 0.6)";
        title.y = @16;
        hioptions.title = title;
        
        HISubtitle *subtitle = [[HISubtitle alloc]init];
        subtitle.text = options[@"subtitle"];
        if ([subtitle.text length] > 0) {
            subtitle.text = [subtitle.text stringByAppendingString:@" total"];
        }
        subtitle.align = @"left";
        subtitle.style = [[HICSSObject alloc] init];
        subtitle.style.fontFamily = @"Arial";
        subtitle.style.fontSize = @"10px";
        subtitle.style.color = @"rgba(255, 255, 255, 0.6)";
        subtitle.y = @28;
        hioptions.subtitle = subtitle;
        
        HITooltip *tooltip = [[HITooltip alloc]init];
        tooltip.headerFormat = @"";
        hioptions.tooltip = tooltip;
        
        HIXAxis *xaxis = [[HIXAxis alloc]init];
        xaxis.tickColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.0];
        xaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        xaxis.labels = [[HILabels alloc]init];
        xaxis.labels.style = [[HICSSObject alloc] init];
        xaxis.labels.style.textOutline = @"10px Arial";
        xaxis.labels.style.color = @"rgb(255, 255, 255)";
        xaxis.labels.step = step;
        xaxis.categories = [categories copy];
        hioptions.xAxis = @[xaxis];
        
        HIYAxis *yaxis = [[HIYAxis alloc]init];
        yaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        yaxis.lineWidth = @1;
        yaxis.gridLineWidth = @0;
        yaxis.labels = [[HILabels alloc]init];
        yaxis.labels.style = [[HICSSObject alloc] init];
        yaxis.labels.style.textOutline = @"10px Arial";
        yaxis.labels.style.color = @"rgb(255, 255, 255)";
        yaxis.labels.x = @-5;
        yaxis.title = [[HITitle alloc]init];
        yaxis.title.text = @"";
        hioptions.yAxis = @[yaxis];
        
        HIArea *area = [[HIArea alloc]init];
        area.tooltip = [[HITooltip alloc]init];
        area.tooltip.headerFormat = @"";
        area.tooltip.valueSuffix = @" steps";
        area.showInLegend = @NO;
        area.data = [series copy];
        area.color = [[HIColor alloc]initWithRGB:255 green:255 blue:255];
        area.name = options[@"title"];
        hioptions.series = @[area];
        
        return hioptions;
    }
    
    if ([options[@"chartType"] isEqualToString:@"column"]) {
        
        HIOptions *hioptions = [[HIOptions alloc]init];
        
        HIChart *chart = [[HIChart alloc]init];
        chart.backgroundColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @300 } stops: @[
                                                                                                                                  @[@0, @"rgb(66, 218, 113)"],
                                                                                                                                  @[@1, @"rgb(80, 140, 200)"]
                                                                                                                                  ]];
        chart.borderRadius = @6;
        chart.type = options[@"chartType"];
        hioptions.chart = chart;
        
        HIExporting *exporting = [[HIExporting alloc]init];
        exporting.enabled = options[@"exporting"];
        hioptions.exporting = exporting;
        
        HINavigation *navigation = [[HINavigation alloc]init];
        navigation.buttonOptions = [[HIButtonOptions alloc]init];
        navigation.buttonOptions.symbolStroke = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.4];
        navigation.buttonOptions.theme = [[HITheme alloc] init];
        navigation.buttonOptions.theme.fill = @"rgba(0,0,0,0.0)";
        hioptions.navigation = navigation;
        
        HIPlotOptions *plotOptions = [[HIPlotOptions alloc]init];
        plotOptions.column = [[HIColumn alloc]init];
        plotOptions.column.color = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.6];
        plotOptions.column.borderRadius = @2;
        plotOptions.column.borderWidth = @0;
        hioptions.plotOptions = plotOptions;
        
        HICredits *credits = [[HICredits alloc]init];
        credits.enabled = @NO;
        hioptions.credits = credits;
        
        HITitle *title = [[HITitle alloc]init];
        title.text = options[@"title"];
        title.align = @"left";
        title.style = [[HICSSObject alloc] init];
        title.style.fontFamily = @"Arial";
        title.style.fontSize = @"14px";
        title.style.color = @"rgba(255, 255, 255, 0.6)";
        title.y = @16;
        hioptions.title = title;
        
        HISubtitle *subtitle = [[HISubtitle alloc]init];
        subtitle.text = options[@"subtitle"];
        if ([subtitle.text length] > 0) {
            subtitle.text = [subtitle.text stringByAppendingString:@" total"];
        }
        subtitle.align = @"left";
        subtitle.style = [[HICSSObject alloc] init];
        subtitle.style.fontFamily = @"Arial";
        subtitle.style.fontSize = @"10px";
        subtitle.style.color = @"rgba(255, 255, 255, 0.6)";
        subtitle.y = @28;
        hioptions.subtitle = subtitle;
        
        HITooltip *tooltip = [[HITooltip alloc]init];
        tooltip.headerFormat = @"";
        hioptions.tooltip = tooltip;
        
        HIXAxis *xaxis = [[HIXAxis alloc]init];
        xaxis.tickColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.0];
        xaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        xaxis.labels = [[HILabels alloc]init];
        xaxis.labels.style = [[HICSSObject alloc] init];
        xaxis.labels.style.color = @"rgb(255, 255, 255)";
        xaxis.labels.style.textOutline = @"10px Arial";
        xaxis.labels.step = step;
        xaxis.categories = [categories copy];
        hioptions.xAxis = @[xaxis];
        
        HIYAxis *yaxis = [[HIYAxis alloc]init];
        yaxis.lineWidth = @1;
        yaxis.gridLineWidth = @0;
        yaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        yaxis.labels = [[HILabels alloc]init];
        yaxis.labels.style = [[HICSSObject alloc] init];
        yaxis.labels.style.color = @"rgb(255, 255, 255)";
        yaxis.labels.style.textOutline = @"10px Arial";
        yaxis.labels.x = @-5;
        yaxis.title = [[HITitle alloc]init];
        yaxis.title.text = @"";
        hioptions.yAxis = @[yaxis];
        
        HIColumn *column = [[HIColumn alloc]init];
        column.tooltip = [[HITooltip alloc]init];
        column.tooltip.headerFormat = @"";
        column.tooltip.valueSuffix = @" kcal";
        column.showInLegend = @NO;
        column.data = [series copy];
        column.name = options[@"title"];
        hioptions.series = @[column];
        
        return hioptions;
    }
    
    if ([options[@"chartType"] isEqualToString:@"spline"]) {
        
        HIOptions *hioptions = [[HIOptions alloc]init];
        
        HIChart *chart = [[HIChart alloc]init];
        chart.backgroundColor = [[HIColor alloc]initWithLinearGradient:@{ @"x1": @0, @"x2": @0, @"y1": @0, @"y2": @300 } stops: @[
                                                                                                                                  @[@0, @"rgba(132, 103, 144, 1)"],
                                                                                                                                  @[@1, @"rgba(163, 95, 103, 1)"]
                                                                                                                                  ]];
        chart.borderRadius = @6;
        chart.type = options[@"chartType"];
        hioptions.chart = chart;
        
        HIExporting *exporting = [[HIExporting alloc]init];
        exporting.enabled = options[@"exporting"];
        hioptions.exporting = exporting;
        
        HINavigation *navigation = [[HINavigation alloc]init];
        navigation.buttonOptions = [[HIButtonOptions alloc]init];
        navigation.buttonOptions.symbolStroke = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.4];
        navigation.buttonOptions.theme = [[HITheme alloc] init];
        navigation.buttonOptions.theme.fill = @"rgba(0,0,0,0.0)";
        hioptions.navigation = navigation;
        
        HIPlotOptions *plotOptions = [[HIPlotOptions alloc]init];
        plotOptions.spline = [[HISpline alloc]init];
        plotOptions.spline.color = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.6];
        hioptions.plotOptions = plotOptions;
        
        HICredits *credits = [[HICredits alloc]init];
        credits.enabled = @NO;
        hioptions.credits = credits;
        
        HITitle *title = [[HITitle alloc]init];
        title.text = options[@"title"];
        title.align = @"left";
        title.style = [[HICSSObject alloc] init];
        title.style.fontFamily = @"Arial";
        title.style.fontSize = @"14px";
        title.style.color = @"rgba(255, 255, 255, 0.6)";
        title.y = @16;
        hioptions.title = title;
        
        HISubtitle *subtitle = [[HISubtitle alloc]init];
        subtitle.text = options[@"subtitle"];
        if ([subtitle.text length] > 0) {
            subtitle.text = [subtitle.text stringByAppendingString:@" total"];
        }
        subtitle.align = @"left";
        subtitle.style = [[HICSSObject alloc] init];
        subtitle.style.fontFamily = @"Arial";
        subtitle.style.fontSize = @"10px";
        subtitle.style.color = @"rgba(255, 255, 255, 0.6)";
        subtitle.y = @28;
        hioptions.subtitle = subtitle;
        
        HITooltip *tooltip = [[HITooltip alloc]init];
        tooltip.headerFormat = @"";
        hioptions.tooltip = tooltip;
        
        HIXAxis *xaxis = [[HIXAxis alloc]init];
        xaxis.tickColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.0];
        xaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        xaxis.labels = [[HILabels alloc]init];
        xaxis.labels.style = [[HICSSObject alloc] init];
        xaxis.labels.style.color = @"rgb(255, 255, 255)";
        xaxis.labels.style.textOutline = @"10px Arial";
        xaxis.labels.step = step;
        xaxis.categories = [categories copy];
        hioptions.xAxis = @[xaxis];
        
        HIYAxis *yaxis = [[HIYAxis alloc]init];
        yaxis.lineWidth = @1;
        yaxis.gridLineWidth = @0;
        yaxis.lineColor = [[HIColor alloc]initWithRGBA:255 green:255 blue:255 alpha:0.3];
        yaxis.labels = [[HILabels alloc]init];
        yaxis.labels.style = [[HICSSObject alloc] init];
        yaxis.labels.style.color = @"rgb(255, 255, 255)";
        yaxis.labels.style.textOutline = @"10px Arial";
        yaxis.labels.x = @-5;
        yaxis.title = [[HITitle alloc]init];
        yaxis.title.text = @"";
        hioptions.yAxis = @[yaxis];
        
        HISpline *spline = [[HISpline alloc]init];
        spline.tooltip = [[HITooltip alloc]init];
        spline.tooltip.headerFormat = @"";
        spline.tooltip.valueSuffix = @" kcal";
        spline.showInLegend = @NO;
        spline.data = [series copy];
        spline.name = options[@"title"];
        hioptions.series = @[spline];
        
        return hioptions;
    }
    
    return nil;
}

@end
