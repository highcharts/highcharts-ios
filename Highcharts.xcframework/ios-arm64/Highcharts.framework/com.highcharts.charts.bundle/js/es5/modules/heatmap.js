!/**
 * Highmaps JS v11.4.3 (2024-05-22)
 *
 * (c) 2009-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/modules/heatmap",["highcharts"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function o(t,e,o,i){t.hasOwnProperty(e)||(t[e]=i.apply(null,o),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:t[e]}})))}o(e,"Core/Axis/Color/ColorAxisComposition.js",[e["Core/Color/Color.js"],e["Core/Utilities.js"]],function(t,e){var o,i=t.parse,r=e.addEvent,s=e.extend,a=e.merge,n=e.pick,l=e.splat;return function(t){var e;function o(){var t=this,o=this.userOptions;this.colorAxis=[],o.colorAxis&&(o.colorAxis=l(o.colorAxis),o.colorAxis.map(function(o){return new e(t,o)}))}function h(t){var e,o,i=this,r=this.chart.colorAxis||[],s=function(e){var o=t.allItems.indexOf(e);-1!==o&&(i.destroyItem(t.allItems[o]),t.allItems.splice(o,1))},a=[];for(r.forEach(function(t){(e=t.options)&&e.showInLegend&&(e.dataClasses&&e.visible?a=a.concat(t.getDataClassLegendSymbols()):e.visible&&a.push(t),t.series.forEach(function(t){(!t.options.showInLegend||e.dataClasses)&&("point"===t.options.legendType?t.points.forEach(function(t){s(t)}):s(t))}))}),o=a.length;o--;)t.allItems.unshift(a[o])}function p(t){t.visible&&t.item.legendColor&&t.item.legendItem.symbol.attr({fill:t.item.legendColor})}function c(t){var e;null===(e=this.chart.colorAxis)||void 0===e||e.forEach(function(e){e.update({},t.redraw)})}function d(){(this.chart.colorAxis&&this.chart.colorAxis.length||this.colorAttribs)&&this.translateColors()}function u(){var t=this.axisTypes;t?-1===t.indexOf("colorAxis")&&t.push("colorAxis"):this.axisTypes=["colorAxis"]}function f(t){var e=this,o=t?"show":"hide";e.visible=e.options.visible=!!t,["graphic","dataLabel"].forEach(function(t){e[t]&&e[t][o]()}),this.series.buildKDTree()}function y(){var t=this,e=this.data.length?this.data:this.points,o=this.options.nullColor,i=this.colorAxis,r=this.colorKey;e.forEach(function(e){var s=e.getNestedProperty(r),a=e.options.color||(e.isNull||null===e.value?o:i&&void 0!==s?i.toColor(s,e):e.color||t.color);a&&e.color!==a&&(e.color=a,"point"===t.options.legendType&&e.legendItem&&e.legendItem.label&&t.chart.legend.colorizeItem(e,e.visible))})}function m(){this.elem.attr("fill",i(this.start).tweenTo(i(this.end),this.pos),void 0,!0)}function g(){this.elem.attr("stroke",i(this.start).tweenTo(i(this.end),this.pos),void 0,!0)}t.compose=function(t,i,l,v,x){var C,b=i.prototype,A=l.prototype,w=x.prototype;b.collectionsWithUpdate.includes("colorAxis")||(e=t,b.collectionsWithUpdate.push("colorAxis"),b.collectionsWithInit.colorAxis=[b.addColorAxis],r(i,"afterGetAxes",o),C=i.prototype.createAxis,i.prototype.createAxis=function(t,o){if("colorAxis"!==t)return C.apply(this,arguments);var i=new e(this,a(o.axis,{index:this[t].length,isX:!1}));return this.isDirtyLegend=!0,this.axes.forEach(function(t){t.series=[]}),this.series.forEach(function(t){t.bindAxes(),t.isDirtyData=!0}),n(o.redraw,!0)&&this.redraw(o.animation),i},A.fillSetter=m,A.strokeSetter=g,r(v,"afterGetAllItems",h),r(v,"afterColorizeItem",p),r(v,"afterUpdate",c),s(w,{optionalAxis:"colorAxis",translateColors:y}),s(w.pointClass.prototype,{setVisible:f}),r(x,"afterTranslate",d,{order:1}),r(x,"bindAxes",u))},t.pointSetVisible=f}(o||(o={})),o}),o(e,"Core/Axis/Color/ColorAxisDefaults.js",[],function(){return{lineWidth:0,minPadding:0,maxPadding:0,gridLineColor:"#ffffff",gridLineWidth:1,tickPixelInterval:72,startOnTick:!0,endOnTick:!0,offset:0,marker:{animation:{duration:50},width:.01,color:"#999999"},labels:{distance:8,overflow:"justify",rotation:0},minColor:"#e6e9ff",maxColor:"#0022ff",tickLength:5,showInLegend:!0}}),o(e,"Core/Axis/Color/ColorAxisLike.js",[e["Core/Color/Color.js"],e["Core/Utilities.js"]],function(t,e){var o,i,r=t.parse,s=e.merge;return(o=i||(i={})).initDataClasses=function(t){var e,o,i,a=this.chart,n=this.legendItem=this.legendItem||{},l=this.options,h=t.dataClasses||[],p=a.options.chart.colorCount,c=0;this.dataClasses=o=[],n.labels=[];for(var d=0,u=h.length;d<u;++d)e=s(e=h[d]),o.push(e),(a.styledMode||!e.color)&&("category"===l.dataClassColor?(a.styledMode||(p=(i=a.options.colors||[]).length,e.color=i[c]),e.colorIndex=c,++c===p&&(c=0)):e.color=r(l.minColor).tweenTo(r(l.maxColor),u<2?.5:d/(u-1)))},o.initStops=function(){for(var t=this.options,e=this.stops=t.stops||[[0,t.minColor||""],[1,t.maxColor||""]],o=0,i=e.length;o<i;++o)e[o].color=r(e[o][1])},o.normalizedValue=function(t){var e=this.max||0,o=this.min||0;return this.logarithmic&&(t=this.logarithmic.log2lin(t)),1-(e-t)/(e-o||1)},o.toColor=function(t,e){var o,i,r,s,a,n,l=this.dataClasses,h=this.stops;if(l){for(n=l.length;n--;)if(i=(a=l[n]).from,r=a.to,(void 0===i||t>=i)&&(void 0===r||t<=r)){s=a.color,e&&(e.dataClass=n,e.colorIndex=a.colorIndex);break}}else{for(o=this.normalizedValue(t),n=h.length;n--&&!(o>h[n][0]););i=h[n]||h[n+1],o=1-((r=h[n+1]||i)[0]-o)/(r[0]-i[0]||1),s=i.color.tweenTo(r.color,o)}return s},i}),o(e,"Core/Axis/Color/ColorAxis.js",[e["Core/Axis/Axis.js"],e["Core/Axis/Color/ColorAxisComposition.js"],e["Core/Axis/Color/ColorAxisDefaults.js"],e["Core/Axis/Color/ColorAxisLike.js"],e["Core/Defaults.js"],e["Core/Legend/LegendSymbol.js"],e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e,o,i,r,s,a,n){var l,h=this&&this.__extends||(l=function(t,e){return(l=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function o(){this.constructor=t}l(t,e),t.prototype=null===e?Object.create(e):(o.prototype=e.prototype,new o)}),p=r.defaultOptions,c=a.series,d=n.defined,u=n.extend,f=n.fireEvent,y=n.isArray,m=n.isNumber,g=n.merge,v=n.pick,x=n.relativeLength;p.colorAxis=g(p.xAxis,o);var C=function(t){function o(e,o){var i=t.call(this,e,o)||this;return i.coll="colorAxis",i.visible=!0,i.init(e,o),i}return h(o,t),o.compose=function(t,i,r,s){e.compose(o,t,i,r,s)},o.prototype.init=function(e,o){var i=e.options.legend||{},r=o.layout?"vertical"!==o.layout:"vertical"!==i.layout;this.side=o.side||r?2:1,this.reversed=o.reversed||!r,this.opposite=!r,t.prototype.init.call(this,e,o,"colorAxis"),this.userOptions=o,y(e.userOptions.colorAxis)&&(e.userOptions.colorAxis[this.index]=o),o.dataClasses&&this.initDataClasses(o),this.initStops(),this.horiz=r,this.zoomEnabled=!1},o.prototype.hasData=function(){return!!(this.tickPositions||[]).length},o.prototype.setTickPositions=function(){if(!this.dataClasses)return t.prototype.setTickPositions.call(this)},o.prototype.setOptions=function(e){var o=g(p.colorAxis,e,{showEmpty:!1,title:null,visible:this.chart.options.legend.enabled&&!1!==e.visible});t.prototype.setOptions.call(this,o),this.options.crosshair=this.options.marker},o.prototype.setAxisSize=function(){var t,e=this.chart,i=null===(t=this.legendItem)||void 0===t?void 0:t.symbol,r=this.getSize(),s=r.width,a=r.height;i&&(this.left=+i.attr("x"),this.top=+i.attr("y"),this.width=s=+i.attr("width"),this.height=a=+i.attr("height"),this.right=e.chartWidth-this.left-s,this.bottom=e.chartHeight-this.top-a,this.pos=this.horiz?this.left:this.top),this.len=(this.horiz?s:a)||o.defaultLegendLength},o.prototype.getOffset=function(){var e,i=null===(e=this.legendItem)||void 0===e?void 0:e.group,r=this.chart.axisOffset[this.side];if(i){this.axisParent=i,t.prototype.getOffset.call(this);var s=this.chart.legend;s.allItems.forEach(function(t){t instanceof o&&t.drawLegendSymbol(s,t)}),s.render(),this.chart.getMargins(!0),this.chart.series.some(function(t){return t.isDrilling})||(this.isDirty=!0),this.added||(this.added=!0,this.labelLeft=0,this.labelRight=this.width),this.chart.axisOffset[this.side]=r}},o.prototype.setLegendColor=function(){var t=this.horiz,e=this.reversed,o=e?1:0,i=e?0:1,r=t?[o,0,i,0]:[0,i,0,o];this.legendColor={linearGradient:{x1:r[0],y1:r[1],x2:r[2],y2:r[3]},stops:this.stops}},o.prototype.drawLegendSymbol=function(t,e){var o,i=e.legendItem||{},r=t.padding,s=t.options,a=this.options.labels,n=v(s.itemDistance,10),l=this.horiz,h=this.getSize(),p=h.width,c=h.height,d=v(s.labelPadding,l?16:30);this.setLegendColor(),i.symbol||(i.symbol=this.chart.renderer.symbol("roundedRect").attr({r:null!==(o=s.symbolRadius)&&void 0!==o?o:3,zIndex:1}).add(i.group)),i.symbol.attr({x:0,y:(t.baseline||0)-11,width:p,height:c}),i.labelWidth=p+r+(l?n:v(a.x,a.distance)+(this.maxLabelLength||0)),i.labelHeight=c+r+(l?d:0)},o.prototype.setState=function(t){this.series.forEach(function(e){e.setState(t)})},o.prototype.setVisible=function(){},o.prototype.getSeriesExtremes=function(){var t,e,o,i,r,s,a,n,l=this.series,h=l.length;for(this.dataMin=1/0,this.dataMax=-1/0;h--;){if(e=(s=l[h]).colorKey=v(s.options.colorKey,s.colorKey,s.pointValKey,s.zoneAxis,"y"),i=s.pointArrayMap,r=s[e+"Min"]&&s[e+"Max"],s[e+"Data"])t=s[e+"Data"];else if(i){if(t=[],o=i.indexOf(e),a=s.yData,o>=0&&a)for(n=0;n<a.length;n++)t.push(v(a[n][o],a[n]))}else t=s.yData;if(r)s.minColorValue=s[e+"Min"],s.maxColorValue=s[e+"Max"];else{var p=c.prototype.getExtremes.call(s,t);s.minColorValue=p.dataMin,s.maxColorValue=p.dataMax}d(s.minColorValue)&&d(s.maxColorValue)&&(this.dataMin=Math.min(this.dataMin,s.minColorValue),this.dataMax=Math.max(this.dataMax,s.maxColorValue)),r||c.prototype.applyExtremes.call(s)}},o.prototype.drawCrosshair=function(e,o){var i,r=this.legendItem||{},s=o&&o.plotX,a=o&&o.plotY,n=this.pos,l=this.len;o&&((i=this.toPixels(o.getNestedProperty(o.series.colorKey)))<n?i=n-2:i>n+l&&(i=n+l+2),o.plotX=i,o.plotY=this.len-i,t.prototype.drawCrosshair.call(this,e,o),o.plotX=s,o.plotY=a,this.cross&&!this.cross.addedToColorAxis&&r.group&&(this.cross.addClass("highcharts-coloraxis-marker").add(r.group),this.cross.addedToColorAxis=!0,this.chart.styledMode||"object"!=typeof this.crosshair||this.cross.attr({fill:this.crosshair.color})))},o.prototype.getPlotLinePath=function(e){var o=this.left,i=e.translatedValue,r=this.top;return m(i)?this.horiz?[["M",i-4,r-6],["L",i+4,r-6],["L",i,r],["Z"]]:[["M",o,i],["L",o-6,i+6],["L",o-6,i-6],["Z"]]:t.prototype.getPlotLinePath.call(this,e)},o.prototype.update=function(e,o){var i=this.chart.legend;this.series.forEach(function(t){t.isDirtyData=!0}),(e.dataClasses&&i.allItems||this.dataClasses)&&this.destroyItems(),t.prototype.update.call(this,e,o),this.legendItem&&this.legendItem.label&&(this.setLegendColor(),i.colorizeItem(this,!0))},o.prototype.destroyItems=function(){var t=this.chart,e=this.legendItem||{};if(e.label)t.legend.destroyItem(this);else if(e.labels)for(var o=0,i=e.labels;o<i.length;o++){var r=i[o];t.legend.destroyItem(r)}t.isDirtyLegend=!0},o.prototype.destroy=function(){this.chart.isDirtyLegend=!0,this.destroyItems(),t.prototype.destroy.apply(this,[].slice.call(arguments))},o.prototype.remove=function(e){this.destroyItems(),t.prototype.remove.call(this,e)},o.prototype.getDataClassLegendSymbols=function(){var t,e=this,o=e.chart,i=e.legendItem&&e.legendItem.labels||[],r=o.options.legend,a=v(r.valueDecimals,-1),n=v(r.valueSuffix,""),l=function(t){return e.series.reduce(function(e,o){return e.push.apply(e,o.points.filter(function(e){return e.dataClass===t})),e},[])};return i.length||e.dataClasses.forEach(function(r,h){var p=r.from,c=r.to,d=o.numberFormatter,y=!0;t="",void 0===p?t="< ":void 0===c&&(t="> "),void 0!==p&&(t+=d(p,a)+n),void 0!==p&&void 0!==c&&(t+=" - "),void 0!==c&&(t+=d(c,a)+n),i.push(u({chart:o,name:t,options:{},drawLegendSymbol:s.rectangle,visible:!0,isDataClass:!0,setState:function(t){for(var e=0,o=l(h);e<o.length;e++)o[e].setState(t)},setVisible:function(){this.visible=y=e.visible=!y;for(var t=[],i=0,r=l(h);i<r.length;i++){var s=r[i];s.setVisible(y),s.hiddenInDataClass=!y,-1===t.indexOf(s.series)&&t.push(s.series)}o.legend.colorizeItem(this,y),t.forEach(function(t){f(t,"afterDataClassLegendClick")})}},r))}),i},o.prototype.getSize=function(){var t=this.chart,e=this.horiz,i=this.options,r=i.height,s=i.width,a=t.options.legend;return{width:v(d(s)?x(s,t.chartWidth):void 0,null==a?void 0:a.symbolWidth,e?o.defaultLegendLength:12),height:v(d(r)?x(r,t.chartHeight):void 0,null==a?void 0:a.symbolHeight,e?12:o.defaultLegendLength)}},o.defaultLegendLength=200,o.keepProps=["legendItem"],o}(t);return u(C.prototype,i),Array.prototype.push.apply(t.keepProps,C.keepProps),C}),o(e,"masters/modules/coloraxis.src.js",[e["Core/Globals.js"],e["Core/Axis/Color/ColorAxis.js"]],function(t,e){return t.ColorAxis=t.ColorAxis||e,t.ColorAxis.compose(t.Chart,t.Fx,t.Legend,t.Series),t}),o(e,"Series/ColorMapComposition.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Renderer/SVG/SVGElement.js"],e["Core/Utilities.js"]],function(t,e,o){var i,r=t.seriesTypes.column.prototype,s=o.addEvent,a=o.defined;return function(t){function o(t){var o=this.series,i=o.chart.renderer;this.moveToTopOnHover&&this.graphic&&(o.stateMarkerGraphic||(o.stateMarkerGraphic=new e(i,"use").css({pointerEvents:"none"}).add(this.graphic.parentGroup)),(null==t?void 0:t.state)==="hover"?(this.graphic.attr({id:this.id}),o.stateMarkerGraphic.attr({href:"".concat(i.url,"#").concat(this.id),visibility:"visible"})):o.stateMarkerGraphic.attr({href:""}))}t.pointMembers={dataLabelOnNull:!0,moveToTopOnHover:!0,isValid:function(){return null!==this.value&&this.value!==1/0&&this.value!==-1/0&&(void 0===this.value||!isNaN(this.value))}},t.seriesMembers={colorKey:"value",axisTypes:["xAxis","yAxis","colorAxis"],parallelArrays:["x","y","value"],pointArrayMap:["value"],trackerGroups:["group","markerGroup","dataLabelsGroup"],colorAttribs:function(t){var e={};return a(t.color)&&(!t.state||"normal"===t.state)&&(e[this.colorProp||"fill"]=t.color),e},pointAttribs:r.pointAttribs},t.compose=function(t){return s(t.prototype.pointClass,"afterSetState",o),t}}(i||(i={})),i}),o(e,"Series/Heatmap/HeatmapPoint.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var o,i=this&&this.__extends||(o=function(t,e){return(o=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function i(){this.constructor=t}o(t,e),t.prototype=null===e?Object.create(e):(i.prototype=e.prototype,new i)}),r=t.seriesTypes.scatter.prototype.pointClass,s=e.clamp,a=e.defined,n=e.extend,l=e.pick,h=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return i(e,t),e.prototype.applyOptions=function(e,o){return(this.isNull||null===this.value)&&delete this.color,t.prototype.applyOptions.call(this,e,o),this.formatPrefix=this.isNull||null===this.value?"null":"point",this},e.prototype.getCellAttributes=function(){for(var t=this.series,e=t.options,o=(e.colsize||1)/2,i=(e.rowsize||1)/2,r=t.xAxis,n=t.yAxis,h=this.options.marker||t.options.marker,p=t.pointPlacementToXValue(),c=l(this.pointPadding,e.pointPadding,0),d={x1:s(Math.round(r.len-r.translate(this.x-o,!1,!0,!1,!0,-p)),-r.len,2*r.len),x2:s(Math.round(r.len-r.translate(this.x+o,!1,!0,!1,!0,-p)),-r.len,2*r.len),y1:s(Math.round(n.translate(this.y-i,!1,!0,!1,!0)),-n.len,2*n.len),y2:s(Math.round(n.translate(this.y+i,!1,!0,!1,!0)),-n.len,2*n.len)},u=0,f=[["width","x"],["height","y"]];u<f.length;u++){var y=f[u],m=y[0],g=y[1],v=g+"1",x=g+"2",C=Math.abs(d[v]-d[x]),b=h&&h.lineWidth||0,A=Math.abs(d[v]+d[x])/2,w=h&&h[m];if(a(w)&&w<C){var M=w/2+b/2;d[v]=A-M,d[x]=A+M}c&&(("x"===g&&r.reversed||"y"===g&&!n.reversed)&&(v=x,x=g+"1"),d[v]+=c,d[x]-=c)}return d},e.prototype.haloPath=function(t){if(!t)return[];var e=this.shapeArgs||{},o=e.x,i=void 0===o?0:o,r=e.y,s=void 0===r?0:r,a=e.width,n=void 0===a?0:a,l=e.height,h=void 0===l?0:l;return[["M",i-t,s-t],["L",i-t,s+h+t],["L",i+n+t,s+h+t],["L",i+n+t,s-t],["Z"]]},e.prototype.isValid=function(){return this.value!==1/0&&this.value!==-1/0},e}(r);return n(h.prototype,{dataLabelOnNull:!0,moveToTopOnHover:!0,ttBelow:!1}),h}),o(e,"Series/Heatmap/HeatmapSeriesDefaults.js",[e["Core/Utilities.js"]],function(t){var e=t.isNumber;return{animation:!1,borderRadius:0,borderWidth:0,interpolation:!1,nullColor:"#f7f7f7",dataLabels:{formatter:function(){var t=this.series.chart.numberFormatter,o=this.point.value;return e(o)?t(o,-1):""},inside:!0,verticalAlign:"middle",crop:!1,overflow:"allow",padding:0},marker:{symbol:"rect",radius:0,lineColor:void 0,states:{hover:{lineWidthPlus:0},select:{}}},clip:!0,pointRange:null,tooltip:{pointFormat:"{point.x}, {point.y}: {point.value}<br/>"},states:{hover:{halo:!1,brightness:.2}},legendSymbol:"rectangle"}}),o(e,"Series/InterpolationUtilities.js",[e["Core/Globals.js"],e["Core/Utilities.js"]],function(t,e){var o=t.doc,i=e.defined,r=e.pick;return{colorFromPoint:function(t,e){var o=e.series.colorAxis;if(o){var s=o.toColor(t||0,e).split(")")[0].split("(")[1].split(",").map(function(t){return r(parseFloat(t),parseInt(t,10))});return s[3]=255*r(s[3],1),i(t)&&e.visible||(s[3]=0),s}return[0,0,0,0]},getContext:function(t){var e=t.canvas,i=t.context;return e&&i?(i.clearRect(0,0,e.width,e.height),i):(t.canvas=o.createElement("canvas"),t.context=t.canvas.getContext("2d",{willReadFrequently:!0})||void 0,t.context)}}}),o(e,"Series/Heatmap/HeatmapSeries.js",[e["Core/Color/Color.js"],e["Series/ColorMapComposition.js"],e["Series/Heatmap/HeatmapPoint.js"],e["Series/Heatmap/HeatmapSeriesDefaults.js"],e["Core/Series/SeriesRegistry.js"],e["Core/Renderer/SVG/SVGRenderer.js"],e["Core/Utilities.js"],e["Series/InterpolationUtilities.js"]],function(t,e,o,i,r,s,a,n){var l,h=this&&this.__extends||(l=function(t,e){return(l=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function o(){this.constructor=t}l(t,e),t.prototype=null===e?Object.create(e):(o.prototype=e.prototype,new o)}),p=this&&this.__assign||function(){return(p=Object.assign||function(t){for(var e,o=1,i=arguments.length;o<i;o++)for(var r in e=arguments[o])Object.prototype.hasOwnProperty.call(e,r)&&(t[r]=e[r]);return t}).apply(this,arguments)},c=r.series,d=r.seriesTypes,u=d.column,f=d.scatter,y=s.prototype.symbols,m=a.addEvent,g=a.extend,v=a.fireEvent,x=a.isNumber,C=a.merge,b=a.pick,A=n.colorFromPoint,w=n.getContext,M=function(e){function o(){var t=null!==e&&e.apply(this,arguments)||this;return t.valueMax=NaN,t.valueMin=NaN,t.isDirtyCanvas=!0,t}return h(o,e),o.prototype.drawPoints=function(){var t=this,e=t.options,o=e.interpolation,i=e.marker||{};if(o){var r=t.image,s=t.chart,a=t.xAxis,n=t.yAxis,l=a.reversed,h=a.len,d=n.reversed,u=n.len,f={width:h,height:u};if(!r||t.isDirtyData||t.isDirtyCanvas){var y=w(t),m=t.canvas,g=t.options,v=g.colsize,x=g.rowsize,C=t.points,b=t.points.length,M=s.colorAxis&&s.colorAxis[0];if(m&&y&&M){var k=a.getExtremes(),j=k.min,L=k.max,S=n.getExtremes(),I=S.min,P=S.max,O=L-j,D=P-I,E=Math.round(O/(void 0===v?1:v)/8*8),T=Math.round(D/(void 0===x?1:x)/8*8),_=[[E,E/O,void 0!==l&&l,"ceil"],[T,T/D,!(void 0!==d&&d),"floor"]].map(function(t){var e=t[0],o=t[1],i=t[2],r=t[3];return i?function(t){return Math[r](e-o*t)}:function(t){return Math[r](o*t)}}),z=_[0],V=_[1],R=m.width=E+1,G=R*(m.height=T+1),H=(b-1)/G,N=new Uint8ClampedArray(4*G);t.buildKDTree();for(var U=0;U<G;U++){var W=C[Math.ceil(H*U)],K=W.x,F=W.y;N.set(A(W.value,W),4*Math.ceil(R*V(F-I)+z(K-j)))}y.putImageData(new ImageData(N,R),0,0),r?r.attr(p(p({},f),{href:m.toDataURL("image/png",1)})):(t.directTouch=!1,t.image=s.renderer.image(m.toDataURL("image/png",1)).attr(f).add(t.group))}t.isDirtyCanvas=!1}else(r.width!==h||r.height!==u)&&r.attr(f)}else(i.enabled||t._hasPointMarkers)&&(c.prototype.drawPoints.call(t),t.points.forEach(function(e){e.graphic&&(e.graphic[t.chart.styledMode?"css":"animate"](t.colorAttribs(e)),null===e.value&&e.graphic.addClass("highcharts-null-point"))}))},o.prototype.getExtremes=function(){var t=c.prototype.getExtremes.call(this,this.valueData),e=t.dataMin,o=t.dataMax;return x(e)&&(this.valueMin=e),x(o)&&(this.valueMax=o),c.prototype.getExtremes.call(this)},o.prototype.getValidPoints=function(t,e){return c.prototype.getValidPoints.call(this,t,e,!0)},o.prototype.hasData=function(){return!!this.processedXData.length},o.prototype.init=function(){e.prototype.init.apply(this,arguments);var t=this.options;t.pointRange=b(t.pointRange,t.colsize||1),this.yAxis.axisPointRange=t.rowsize||1,y.ellipse=y.circle,t.marker&&x(t.borderRadius)&&(t.marker.r=t.borderRadius)},o.prototype.markerAttribs=function(t,e){var o=t.shapeArgs||{};if(t.hasImage)return{x:t.plotX,y:t.plotY};if(e&&"normal"!==e){var i=t.options.marker||{},r=this.options.marker||{},s=r.states&&r.states[e]||{},a=i.states&&i.states[e]||{},n=(a.width||s.width||o.width||0)+(a.widthPlus||s.widthPlus||0),l=(a.height||s.height||o.height||0)+(a.heightPlus||s.heightPlus||0);return{x:(o.x||0)+((o.width||0)-n)/2,y:(o.y||0)+((o.height||0)-l)/2,width:n,height:l}}return o},o.prototype.pointAttribs=function(e,o){var i=c.prototype.pointAttribs.call(this,e,o),r=this.options||{},s=this.chart.options.plotOptions||{},a=s.series||{},n=s.heatmap||{},l=e&&e.options.borderColor||r.borderColor||n.borderColor||a.borderColor,h=e&&e.options.borderWidth||r.borderWidth||n.borderWidth||a.borderWidth||i["stroke-width"];if(i.stroke=e&&e.marker&&e.marker.lineColor||r.marker&&r.marker.lineColor||l||this.color,i["stroke-width"]=h,o&&"normal"!==o){var p=C(r.states&&r.states[o],r.marker&&r.marker.states&&r.marker.states[o],e&&e.options.states&&e.options.states[o]||{});i.fill=p.color||t.parse(i.fill).brighten(p.brightness||0).get(),i.stroke=p.lineColor||i.stroke}return i},o.prototype.translate=function(){var t=this.options,e=t.borderRadius,o=t.marker,i=o&&o.symbol||"rect",r=y[i]?i:"rect",s=-1!==["circle","square"].indexOf(r);this.generatePoints();for(var a=0,n=this.points;a<n.length;a++){var l=n[a],h=l.getCellAttributes(),p=Math.min(h.x1,h.x2),c=Math.min(h.y1,h.y2),d=Math.max(Math.abs(h.x2-h.x1),0),u=Math.max(Math.abs(h.y2-h.y1),0);if(l.hasImage=0===(l.marker&&l.marker.symbol||i||"").indexOf("url"),s){var f=Math.abs(d-u);p=Math.min(h.x1,h.x2)+(d<u?0:f/2),c=Math.min(h.y1,h.y2)+(d<u?f/2:0),d=u=Math.min(d,u)}l.hasImage&&(l.marker={width:d,height:u}),l.plotX=l.clientX=(h.x1+h.x2)/2,l.plotY=(h.y1+h.y2)/2,l.shapeType="path",l.shapeArgs=C(!0,{x:p,y:c,width:d,height:u},{d:y[r](p,c,d,u,{r:x(e)?e:0})})}v(this,"afterTranslate")},o.defaultOptions=C(f.defaultOptions,i),o}(f);return m(M,"afterDataClassLegendClick",function(){this.isDirtyCanvas=!0,this.drawPoints()}),g(M.prototype,{axisTypes:e.seriesMembers.axisTypes,colorKey:e.seriesMembers.colorKey,directTouch:!0,getExtremesFromAll:!0,parallelArrays:e.seriesMembers.parallelArrays,pointArrayMap:["y","value"],pointClass:o,specialGroup:"group",trackerGroups:e.seriesMembers.trackerGroups,alignDataLabel:u.prototype.alignDataLabel,colorAttribs:e.seriesMembers.colorAttribs,getSymbol:c.prototype.getSymbol}),e.compose(M),r.registerSeriesType("heatmap",M),M}),o(e,"masters/modules/heatmap.src.js",[e["Core/Globals.js"]],function(t){return t})});