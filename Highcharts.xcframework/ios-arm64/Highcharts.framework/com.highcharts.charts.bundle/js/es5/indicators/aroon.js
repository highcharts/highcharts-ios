!/**
 * Highstock JS v11.4.5 (2024-07-04)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Wojciech Chmiel
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/aroon",["highcharts","highcharts/modules/stock"],function(o){return t(o),t.Highcharts=o,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var o=t?t._modules:{};function e(o,e,n,r){o.hasOwnProperty(e)||(o[e]=r.apply(null,n),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:o[e]}})))}e(o,"Stock/Indicators/MultipleLinesComposition.js",[o["Core/Series/SeriesRegistry.js"],o["Core/Utilities.js"]],function(t,o){var e,n=t.seriesTypes.sma.prototype,r=o.defined,i=o.error,a=o.merge;return function(t){var o=["bottomLine"],e=["top","bottom"],s=["top"];function p(t){return"plot"+t.charAt(0).toUpperCase()+t.slice(1)}function l(t,o){var e=[];return(t.pointArrayMap||[]).forEach(function(t){t!==o&&e.push(p(t))}),e}function c(){var t,o=this,e=o.pointValKey,s=o.linesApiNames,c=o.areaLinesNames,h=o.points,u=o.options,f=o.graph,d={options:{gapSize:u.gapSize}},y=[],m=l(o,e),g=h.length;if(m.forEach(function(o,e){for(y[e]=[];g--;)t=h[g],y[e].push({x:t.x,plotX:t.plotX,plotY:t[o],isNull:!r(t[o])});g=h.length}),o.userOptions.fillColor&&c.length){var v=y[m.indexOf(p(c[0]))],A=1===c.length?h:y[m.indexOf(p(c[1]))],x=o.color;o.points=A,o.nextPoints=v,o.color=o.userOptions.fillColor,o.options=a(h,d),o.graph=o.area,o.fillGraph=!0,n.drawGraph.call(o),o.area=o.graph,delete o.nextPoints,delete o.fillGraph,o.color=x}s.forEach(function(t,e){y[e]?(o.points=y[e],u[t]?o.options=a(u[t].styles,d):i('Error: "There is no '+t+' in DOCS options declared. Check if linesApiNames are consistent with your DOCS line names."'),o.graph=o["graph"+t],n.drawGraph.call(o),o["graph"+t]=o.graph):i('Error: "'+t+" doesn't have equivalent in pointArrayMap. To many elements in linesApiNames relative to pointArrayMap.\"")}),o.points=h,o.options=u,o.graph=f,n.drawGraph.call(o)}function h(t){var o,e=[],r=[];if(t=t||this.points,this.fillGraph&&this.nextPoints){if((o=n.getGraphPath.call(this,this.nextPoints))&&o.length){o[0][0]="L",e=n.getGraphPath.call(this,t),r=o.slice(0,e.length);for(var i=r.length-1;i>=0;i--)e.push(r[i])}}else e=n.getGraphPath.apply(this,arguments);return e}function u(t){var o=[];return(this.pointArrayMap||[]).forEach(function(e){o.push(t[e])}),o}function f(){var t,o=this,e=this.pointArrayMap,r=[];r=l(this),n.translate.apply(this,arguments),this.points.forEach(function(n){e.forEach(function(e,i){t=n[e],o.dataModify&&(t=o.dataModify.modifyValue(t)),null!==t&&(n[r[i]]=o.yAxis.toPixels(t,!0))})})}t.compose=function(t){var n=t.prototype;return n.linesApiNames=n.linesApiNames||o.slice(),n.pointArrayMap=n.pointArrayMap||e.slice(),n.pointValKey=n.pointValKey||"top",n.areaLinesNames=n.areaLinesNames||s.slice(),n.drawGraph=c,n.getGraphPath=h,n.toYData=u,n.translate=f,t}}(e||(e={})),e}),e(o,"Stock/Indicators/Aroon/AroonIndicator.js",[o["Stock/Indicators/MultipleLinesComposition.js"],o["Core/Series/SeriesRegistry.js"],o["Core/Utilities.js"]],function(t,o,e){var n,r=this&&this.__extends||(n=function(t,o){return(n=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,o){t.__proto__=o}||function(t,o){for(var e in o)Object.prototype.hasOwnProperty.call(o,e)&&(t[e]=o[e])})(t,o)},function(t,o){if("function"!=typeof o&&null!==o)throw TypeError("Class extends value "+String(o)+" is not a constructor or null");function e(){this.constructor=t}n(t,o),t.prototype=null===o?Object.create(o):(e.prototype=o.prototype,new e)}),i=o.seriesTypes.sma,a=e.extend,s=e.merge,p=e.pick;function l(t,o){var e,n=t[0],r=0;for(e=1;e<t.length;e++)("max"===o&&t[e]>=n||"min"===o&&t[e]<=n)&&(n=t[e],r=e);return r}var c=function(t){function o(){return null!==t&&t.apply(this,arguments)||this}return r(o,t),o.prototype.getValues=function(t,o){var e,n,r,i,a,s=o.period,c=t.xData,h=t.yData,u=h?h.length:0,f=[],d=[],y=[];for(i=s-1;i<u;i++)r=l((a=h.slice(i-s+1,i+2)).map(function(t){return p(t[2],t)}),"min"),e=l(a.map(function(t){return p(t[1],t)}),"max")/s*100,n=r/s*100,c[i+1]&&(f.push([c[i+1],e,n]),d.push(c[i+1]),y.push([e,n]));return{values:f,xData:d,yData:y}},o.defaultOptions=s(i.defaultOptions,{params:{index:void 0,period:25},marker:{enabled:!1},tooltip:{pointFormat:'<span style="color:{point.color}">●</span><b> {series.name}</b><br/>Aroon Up: {point.y}<br/>Aroon Down: {point.aroonDown}<br/>'},aroonDown:{styles:{lineWidth:1,lineColor:void 0}},dataGrouping:{approximation:"averages"}}),o}(i);return a(c.prototype,{areaLinesNames:[],linesApiNames:["aroonDown"],nameBase:"Aroon",pointArrayMap:["y","aroonDown"],pointValKey:"y"}),t.compose(c),o.registerSeriesType("aroon",c),c}),e(o,"masters/indicators/aroon.src.js",[o["Core/Globals.js"]],function(t){return t})});