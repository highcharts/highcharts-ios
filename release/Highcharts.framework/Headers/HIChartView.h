/**
 * (c) 2009-2018 Highsoft AS
 *
 * License: www.highcharts.com/license
 * For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
 * In case of questions, please contact sales@highsoft.com
 */

#import <UIKit/UIKit.h>
#import "HIOptions.h"
#import "HIGChartViewDelegate.h"
#import "HILang.h"
#import "HIGlobal.h"

/**
 *  Highcharts Chart View Class.
 *  @warning The view requires #options# to render.
 */
@interface HIChartView : UIView

/**
 *  An optional method to be called when the application starts. Speeds up subsequent chart loads.
 *
 *  @note In case of using #addFont:#, calling `preload` isn't necessary.
 */
+ (void)preload;

/**
 *  A method to add a custom font to the chart.
 *
 *  @param path an absolute path pointing to the location of the font.
 *
 *  @note Calling #preload# isn't necessary.
 */
+ (void)addFont:(NSString *)path;

/**
 *  A method for update the chart options manually.
 */
- (void)updateOptions;

/**
 *  A method to load the chart options from JSON.
 *
 * @param options chart options in JSON format.
 */
- (void)loadJSONOptions:(NSDictionary*)options;

/**
 *  Options object that configures the chart.
 */
@property (strong, nonatomic) HIOptions *options;

/**
 *  Language object. The language object is global and it can't be set on each chart initiation.
 */
@property (strong, nonatomic) HILang *lang;

/**
 *  Global object. Global options that don't apply to each chart.
 */
@property (strong, nonatomic) HIGlobal *global;

/**
 *  Theme name to load.
 */
@property (strong, nonatomic) NSString *theme;

/**
 *  Additional plugins to load.
 */
@property (strong, nonatomic) NSArray *plugins;

/**
 *  The chart might need to understand its encompassing UIViewController to properly export itself into an image.
 */
@property (weak, nonatomic) UIViewController *viewController;

/**
 *  A delegate that notifies on chart state changes.
 */
@property (weak, nonatomic) id<HIChartViewDelegate> delegate;

/**
 *  An optional property to 'synchronously' render the chart.
 *
 *  **Defaults to** `false`.
 *
 *  @note Usage not recommended.
 */
@property (class, nonatomic) NSNumber /* Bool */ *synced;

/**
 * A method to share the chart in PNG format.
 */
- (void)exportToPNG;

/**
 * A method to share the chart in PDF format.
 */
- (void)exportToPDF;

/**
 * A method to share the chart in CSV format.
 */
- (void)exportToCSV;

/**
 Add an annotation to the chart after render time.
 @param options The annotation options for the new, detailed annotation.
 */
-(void)addAnnotation:(HIAnnotations *)options;

/**
 Add an annotation to the chart after render time.
 @param options The annotation options for the new, detailed annotation.
 @param redraw Whether to redraw the chart.
 */
-(void)addAnnotation:(HIAnnotations *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 */
-(void)addXAxis:(HIXAxis *)options;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 @param redraw Whether to redraw the chart after adding.
 */
-(void)addXAxis:(HIXAxis *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 @param redraw Whether to redraw the chart after adding.
 @param animation Whether and how to apply animation in the redraw.
 */
-(void)addXAxis:(HIXAxis *)options redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 */
-(void)addYAxis:(HIYAxis *)options;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 @param redraw Whether to redraw the chart after adding.
 */
-(void)addYAxis:(HIYAxis *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Add an axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.
 
 **Try it**
 
 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)
 
 @param options The axis options.
 @param redraw Whether to redraw the chart after adding.
 @param animation Whether and how to apply animation in the redraw.
 */
-(void)addYAxis:(HIYAxis *)options redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Add a color axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.

 **Try it**

 * [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)

 @param options The axis options.
 */
-(void)addColorAxis:(HIColorAxis *)options;

/**
Add a color axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.

**Try it**

* [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)

@param options The axis options.
@param redraw Whether to redraw the chart after adding.
*/
-(void)addColorAxis:(HIColorAxis *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
Add a color axis to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the axis as a configuration option instead.

**Try it**

* [Add and remove axes](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addaxis/)

@param options The axis options.
@param redraw Whether to redraw the chart after adding.
@param animation Whether and how to apply animation in the redraw.
*/
-(void)addColorAxis:(HIColorAxis *)options redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Set a new credits label for the chart.
 
 **Try it**
 
 * [Add and update credits](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/credits/credits-update/)
 
 @param options A configuration object for the new credits.
 */
-(void)addCredits:(HICredits *)options;

/**
 Add a series to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the series as a configuration option instead. With multiple axes, the `offset` is dynamically adjusted.
 
 **Fires:**
 
 * Highcharts.Chart#event:addSeries
 * Highcharts.Chart#event:afterAddSeries
 
 **Try it**
 
 * [Add a series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addseries/)
 
 @param options The config options for the series.
 */
-(void)addSeries:(HISeries *)options;

/**
 Add a series to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the series as a configuration option instead. With multiple axes, the `offset` is dynamically adjusted.
 
 **Fires:**
 
 * Highcharts.Chart#event:addSeries
 * Highcharts.Chart#event:afterAddSeries
 
 **Try it**
 
 * [Add a series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addseries/)
 
 @param options The config options for the series.
 @param redraw Whether to redraw the chart after adding.
 */
-(void)addSeries:(HISeries *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 Add a series to the chart after render time. Note that this method should never be used when adding data synchronously at chart render time, as it adds expense to the calculations and rendering. When adding data at the same time as the chart is initialized, add the series as a configuration option instead. With multiple axes, the `offset` is dynamically adjusted.
 
 **Fires:**
 
 * Highcharts.Chart#event:addSeries
 * Highcharts.Chart#event:afterAddSeries
 
 **Try it**
 
 * [Add a series from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-addseries/)
 
 @param options The config options for the series.
 @param redraw Whether to redraw the chart after adding.
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)addSeries:(HISeries *)options redraw:(NSNumber /* Bool */ *)redraw animation:(HIAnimationOptionsObject *)animation;

/**
 Add a series to the chart as drilldown from a specific point in the parent series. This method is used for async drilldown, when clicking a point in a series should result in loading and displaying a more high-resolution series. When not async, the setup is simpler using the [drilldown.series](https://api.highcharts.com/highcharts/drilldown.series) options structure.
 
 **Try it**
 
 * [Async drilldown](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/drilldown/async/)
 
 @param point The point from which the drilldown will start.
 @param options The series options for the new, detailed series.
 */
-(void)addSeriesAsDrilldown:(HIPoint *)point options:(HISeries *)options;

/**
 Cancel current sonification and reset cursor.
 
 **Requires:**
 
 * module:modules/sonification
 */
-(void)cancelSonify;

/**
 Cancel current sonification and reset cursor.
 
 **Requires:**
 
 * module:modules/sonification
 
 @param fadeOut Fade out as we pause to avoid clicks.
 */
-(void)cancelSonify:(NSNumber /* Bool */ *)fadeOut;

/**
 Remove the chart and purge memory. This method is called internally before adding a second chart into the same container, as well as on window unload to prevent leaks.
 
 **Fires:**
 
 * Highcharts.Chart#event:destroy
 
 **Try it**
 
 * [Destroy the chart from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-destroy/)
 */
-(void)destroy;

/**
 When the chart is drilled down to a child series, calling `chart.drillUp()` will drill up to the parent series. Requires the drilldown module.
 */
-(void)drillUp;

/**
 Hide the loading layer.
 
 **See also:**
 
 * [Highcharts.Chart#showLoading](https://api.highcharts.com/class-reference/Highcharts.Chart#showLoading)
 
 **Try it**
 
 * [Show and hide loading from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-hideloading/)
 */
-(void)hideLoading;

/**
 Experimental function to send a chart's config to the Cloud for editing.
 */
-(void)openInCloud;

/**
 Pause the running sonification.
 
 **Requires:**
 
 * module:modules/sonification
 */
-(void)pauseSonify;

/**
 Pause the running sonification.
 @param fadeOut Fade out as we pause to avoid clicks.
 */
-(void)pauseSonify:(NSNumber /* Bool */ *)fadeOut;

/**
 Exporting module required. Clears away other elements in the page and prints the chart as it is displayed. By default, when the exporting module is enabled, a context button with a drop down menu in the upper right corner accesses this function.
 
 **Fires:**
 
 * Highcharts.Chart#event:beforePrint
 * Highcharts.Chart#event:afterPrint
 
 **Try it**
 
 * [Print from a HTML button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-print/)
 */
-(void)print;

/**
 Redraw the chart after changes have been done to the data, axis extremes chart size or chart elements. All methods for updating axes, series or points have a parameter for redrawing the chart. This is true by default. But in many cases you want to do more than one operation on the chart before redrawing, for example add a number of points. In those cases it is a waste of resources to redraw the chart for each new point added. So you add the points and call `chart.redraw()` after.
 
 **Fires:**
 
 * Highcharts.Chart#event:afterSetExtremes
 * Highcharts.Chart#event:beforeRedraw
 * Highcharts.Chart#event:predraw
 * Highcharts.Chart#event:redraw
 * Highcharts.Chart#event:render
 * Highcharts.Chart#event:updatedData
 */
-(void)redraw;

/**
 Redraw the chart after changes have been done to the data, axis extremes chart size or chart elements. All methods for updating axes, series or points have a parameter for redrawing the chart. This is true by default. But in many cases you want to do more than one operation on the chart before redrawing, for example add a number of points. In those cases it is a waste of resources to redraw the chart for each new point added. So you add the points and call `chart.redraw()` after.
 
 **Fires:**
 
 * Highcharts.Chart#event:afterSetExtremes
 * Highcharts.Chart#event:beforeRedraw
 * Highcharts.Chart#event:predraw
 * Highcharts.Chart#event:redraw
 * Highcharts.Chart#event:render
 * Highcharts.Chart#event:updatedData
 
 @param animation If or how to apply animation to the redraw.
 */
-(void)redraw:(HIAnimationOptionsObject *)animation;

/**
 Remove an annotation from the chart.
 @param id The annotation's id.
 */
-(void)removeAnnotationById:(NSString *)id;

/**
 Remove an annotation from the chart.
 @param annotation The direct annotation object.
 */
-(void)removeAnnotation:(HIAnnotations *)annotation;

/**
 Reset cursor to start. Requires series.sonify or chart.sonify to have been played at some point earlier.
 
 **Requires:**
 
 * module:modules/sonification
 */
-(void)resetSonifyCursor;

/**
 Reset cursor to end. Requires series.sonify or chart.sonify to have been played at some point earlier.
 
 **Requires:**
 
 * module:modules/sonification
 */
-(void)resetSonifyCursorEnd;

/**
 Set the caption options. This can also be done from Highcharts.Chart#update.
 @param options New caption options. The caption text itself is set by the options.text property.
 */
-(void)setCaption:(HICaption *)options;

/**
 Set the chart container's class name, in addition to highcharts-container.
 */
-(void)setClassName;

/**
 Set the chart container's class name, in addition to highcharts-container.
 @param className Class name.
 */
-(void)setClassName:(NSString *)className;

/**
 Set the cursor to a point in different series.
 
 **Requires:**
 
 * module:modules/sonification
 
 @param point The point to set the cursor to.
 */
-(void)setSonifyCursorToPoint:(HIPoint *)point;

/**
 Set the cursor to a set of points in different series.
 
 **Requires:**
 
 * module:modules/sonification
 
 @param points The points to set the cursor to. If setting multiple points under the cursor, the points have to be in different series that are being played simultaneously.
 */
-(void)setSonifyCursorToPoints:(NSArray<HIPoint *> *)points;

/**
 Shortcut to set the subtitle options. This can also be done from [Highcharts.Chart#update](https://api.highcharts.com/class-reference/Highcharts.Chart.html#update) or [Highcharts.Chart#setTitle](https://api.highcharts.com/class-reference/Highcharts.Chart.html#setTitle).
 @param options New subtitle options. The subtitle text itself is set by the `options.text` property.
 */
-(void)setSubtitle:(HISubtitle *)options;

/**
 Set a new title or subtitle for the chart.
 
 **Try it**
 
 * [Set title text and styles](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-settitle/)
 
 @param titleOptions New title options. The title text itself is set by the `titleOptions.text` property.
 @param subtitleOptions New subtitle options. The subtitle text itself is set by the `subtitleOptions.text` property.
 @param redraw Whether to redraw the chart or wait for a later call to `chart.redraw()`.
 */
-(void)setTitle:(HITitle *)titleOptions subtitleOptions:(HISubtitle *)subtitleOptions redraw:(NSNumber /* Bool */ *)redraw;

/**
 Dim the chart and show a loading text or symbol. Options for the loading screen are defined in [the loading options](https://api.highcharts.com/highcharts/loading).
 
 **Try it**
 
 * [Show and hide loading from a button](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-hideloading/)
 * [Apply different text labels](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-showloading/)
 
 @param str An optional text to show in the loading label instead of the default one. The default text is set in [lang.loading](http://api.highcharts.com/highcharts/lang.loading).
 */
-(void)showLoading:(NSString *)str;

/**
 Sonify a chart.
 
 **Requires:**
 
 * module:modules/sonification
 
 **Try it**
 
 * [Sonify a basic chart](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-sequential/)
 * [Sonify series simultaneously](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-simultaneous/)
 * [Custom defined order of series](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-custom-order/)
 * [Earcons on chart](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-earcon/)
 * [Sonification events on chart](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/sonification/chart-events/)
 
 @param options The options for sonifying this chart.
 */
-(void)sonify:(NSDictionary *)options;

/**
 A generic function to update any element of the chart. Elements can be enabled and disabled, moved, re-styled, re-formatted etc.
 
 A special case is configuration objects that take arrays, for example [xAxis](https://api.highcharts.com/highcharts/xAxis), [yAxis](https://api.highcharts.com/highcharts/yAxis) or [series](https://api.highcharts.com/highcharts/series). For these collections, an `id` option is used to map the new option set to an existing object. If an existing object of the same id is not found, the corresponding item is updated. So for example, running `chart.update` with a series item without an id, will cause the existing chart's series with the same index in the series array to be updated. When the `oneToOne` parameter is true, `chart.update` will also take care of adding and removing items from the collection. Read more under the parameter description below.
 
 See also the [responsive option set](https://api.highcharts.com/highcharts/responsive). Switching between `responsive.rules` basically runs `chart.update` under the hood.
 
 **Fires:**
 
 * Highcharts.Chart#event:update
 * Highcharts.Chart#event:afterUpdate
 
 **Try it**
 
 * [Update chart geometry](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-update/)
 
 @param options A configuration object for the new chart options.
 */
-(void)update:(HIOptions *)options;

/**
 A generic function to update any element of the chart. Elements can be enabled and disabled, moved, re-styled, re-formatted etc.
 
 A special case is configuration objects that take arrays, for example [xAxis](https://api.highcharts.com/highcharts/xAxis), [yAxis](https://api.highcharts.com/highcharts/yAxis) or [series](https://api.highcharts.com/highcharts/series). For these collections, an `id` option is used to map the new option set to an existing object. If an existing object of the same id is not found, the corresponding item is updated. So for example, running `chart.update` with a series item without an id, will cause the existing chart's series with the same index in the series array to be updated. When the `oneToOne` parameter is true, `chart.update` will also take care of adding and removing items from the collection. Read more under the parameter description below.
 
 See also the [responsive option set](https://api.highcharts.com/highcharts/responsive). Switching between `responsive.rules` basically runs `chart.update` under the hood.
 
 **Fires:**
 
 * Highcharts.Chart#event:update
 * Highcharts.Chart#event:afterUpdate
 
 **Try it**
 
 * [Update chart geometry](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-update/)
 
 @param options A configuration object for the new chart options.
 @param redraw Whether to redraw the chart.
 */
-(void)update:(HIOptions *)options redraw:(NSNumber /* Bool */ *)redraw;

/**
 A generic function to update any element of the chart. Elements can be enabled and disabled, moved, re-styled, re-formatted etc.
 
 A special case is configuration objects that take arrays, for example [xAxis](https://api.highcharts.com/highcharts/xAxis), [yAxis](https://api.highcharts.com/highcharts/yAxis) or [series](https://api.highcharts.com/highcharts/series). For these collections, an `id` option is used to map the new option set to an existing object. If an existing object of the same id is not found, the corresponding item is updated. So for example, running `chart.update` with a series item without an id, will cause the existing chart's series with the same index in the series array to be updated. When the `oneToOne` parameter is true, `chart.update` will also take care of adding and removing items from the collection. Read more under the parameter description below.
 
 See also the [responsive option set](https://api.highcharts.com/highcharts/responsive). Switching between `responsive.rules` basically runs `chart.update` under the hood.
 
 **Fires:**
 
 * Highcharts.Chart#event:update
 * Highcharts.Chart#event:afterUpdate
 
 **Try it**
 
 * [Update chart geometry](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-update/)
 
 @param options A configuration object for the new chart options.
 @param redraw Whether to redraw the chart.
 @param oneToOne When `true`, the `series`, `xAxis` and `yAxis` collections will be updated one to one, and items will be either added or removed to match the new updated options. For example, if the chart has two series and we call `chart.update` with a configuration containing three series, one will be added. If we call `chart.update` with one series, one will be removed. Setting an empty `series` array will remove all series, but leaving out the `series` property will leave all series untouched. If the series have id's, the new series options will be matched by id, and the remaining ones removed.
 */
-(void)update:(HIOptions *)options redraw:(NSNumber /* Bool */ *)redraw oneToOne:(NSNumber /* Bool */ *)oneToOne;

/**
 A generic function to update any element of the chart. Elements can be enabled and disabled, moved, re-styled, re-formatted etc.
 
 A special case is configuration objects that take arrays, for example [xAxis](https://api.highcharts.com/highcharts/xAxis), [yAxis](https://api.highcharts.com/highcharts/yAxis) or [series](https://api.highcharts.com/highcharts/series). For these collections, an `id` option is used to map the new option set to an existing object. If an existing object of the same id is not found, the corresponding item is updated. So for example, running `chart.update` with a series item without an id, will cause the existing chart's series with the same index in the series array to be updated. When the `oneToOne` parameter is true, `chart.update` will also take care of adding and removing items from the collection. Read more under the parameter description below.
 
 See also the [responsive option set](https://api.highcharts.com/highcharts/responsive). Switching between `responsive.rules` basically runs `chart.update` under the hood.
 
 **Fires:**
 
 * Highcharts.Chart#event:update
 * Highcharts.Chart#event:afterUpdate
 
 **Try it**
 
 * [Update chart geometry](http://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/members/chart-update/)
 
 @param options A configuration object for the new chart options.
 @param redraw Whether to redraw the chart.
 @param oneToOne When `true`, the `series`, `xAxis` and `yAxis` collections will be updated one to one, and items will be either added or removed to match the new updated options. For example, if the chart has two series and we call `chart.update` with a configuration containing three series, one will be added. If we call `chart.update` with one series, one will be removed. Setting an empty `series` array will remove all series, but leaving out the `series` property will leave all series untouched. If the series have id's, the new series options will be matched by id, and the remaining ones removed.
 @param animation Whether to apply animation, and optionally animation configuration.
 */
-(void)update:(HIOptions *)options redraw:(NSNumber /* Bool */ *)redraw oneToOne:(NSNumber /* Bool */ *)oneToOne animation:(HIAnimationOptionsObject *)animation;

/**
 Export-data module required. View the data in a table below the chart.
 */
-(void)viewData;

/**
 Zoom the chart out after a user has zoomed in. See also [Axis.setExtremes](https://api.highcharts.com/class-reference/Highcharts.Axis#setExtremes).
 
 **Fires:**
 
 * Highcharts.Chart#event:selection
 */
-(void)zoomOut;

/**
 *  Deprecated methods and attributes.
 */
@property (assign, nonatomic) BOOL debug __attribute__((deprecated));
- (void)loadChart __attribute__((deprecated));
- (void)reload __attribute__((deprecated));

@end
