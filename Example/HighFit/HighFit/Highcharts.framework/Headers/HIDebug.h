/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Debugging options for boost. Useful for benchmarking, and general timing.
*/
@interface HIDebug: HIChartsJSONSerializable

/**
Time the building of the k-d tree. This outputs the time spent building the k-d tree used for markers etc. Note that the k-d tree is built async, and runs post-rendering. Following, it does not affect the performance of the rendering itself.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *timeKDTree;
/**
Time the series processing. This outputs the time spent on transforming the series data to vertex buffers when set to true.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *timeSeriesProcessing;
/**
Time the WebGL to SVG buffer copy After rendering, the result is copied to an image which is injected into the SVG. If this property is set to true, the time it takes for the buffer copy to complete is outputted.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *timeBufferCopy;
/**
Time the the WebGL setup. This outputs the time spent on setting up the WebGL context, creating shaders, and textures.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *timeSetup;
/**
Time the series rendering. This outputs the time spent on actual rendering in the console when set to true.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *timeRendering;
/**
Show the number of points skipped through culling. When set to true, the number of points skipped in series processing is outputted. Points are skipped if they are closer than 1 pixel from each other.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *showSkipSummary;

-(NSDictionary *)getParams;

@end
