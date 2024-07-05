!/**
 * Highcharts JS v11.4.5 (2024-07-04)
 *
 * (c) 2009-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/draggable-points",["highcharts"],function(r){return e(r),e.Highcharts=r,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var r=e?e._modules:{};function t(r,t,a,o){r.hasOwnProperty(t)||(r[t]=o.apply(null,a),"function"==typeof CustomEvent&&e.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:t,module:r[t]}})))}t(r,"Extensions/DraggablePoints/DragDropUtilities.js",[r["Core/Utilities.js"]],function(e){var r=e.addEvent;return{addEvents:function(e,t,a,o){var i=t.map(function(t){return r(e,t,a,o)});return function(){for(var e=0;e<i.length;e++)(0,i[e])()}},countProps:function(e){return Object.keys(e).length},getFirstProp:function(e){for(var r in e)if(Object.hasOwnProperty.call(e,r))return e[r]},getNormalizedEvent:function(e,r){var t;return(void 0===e.chartX||void 0===e.chartY)&&(null===(t=r.pointer)||void 0===t?void 0:t.normalize(e))||e}}}),t(r,"Extensions/DraggablePoints/DragDropDefaults.js",[],function(){return{dragSensitivity:2,dragHandle:{className:"highcharts-drag-handle",color:"#fff",lineColor:"rgba(0, 0, 0, 0.6)",lineWidth:1,zIndex:901},guideBox:{default:{className:"highcharts-drag-box-default",lineWidth:1,lineColor:"#888",color:"rgba(0, 0, 0, 0.1)",cursor:"move",zIndex:900}}}}),t(r,"Extensions/DraggablePoints/DraggableChart.js",[r["Core/Animation/AnimationUtilities.js"],r["Extensions/DraggablePoints/DragDropUtilities.js"],r["Extensions/DraggablePoints/DragDropDefaults.js"],r["Core/Globals.js"],r["Core/Utilities.js"]],function(e,r,t,a,o){var i=e.animObject,n=r.addEvents,s=r.countProps,d=r.getFirstProp,g=r.getNormalizedEvent,p=a.doc,l=o.addEvent,h=o.merge,u=o.pick;function c(){var e=this.dragHandles||{};if(e){for(var r=0,t=Object.keys(e);r<t.length;r++){var a=t[r];e[a].destroy&&e[a].destroy()}delete this.dragHandles}}function x(e,r){var a=this.dragGuideBox,o=h(t.guideBox,r),i=h(o.default,o[e]);return a.attr({class:i.className,stroke:i.lineColor,strokeWidth:i.lineWidth,fill:i.color,cursor:i.cursor,zIndex:i.zIndex}).css({pointerEvents:"none"})}function f(e){var r=this.options.chart||{},t=r.panKey&&r.panKey+"Key";return e[this.zooming.key&&this.zooming.key+"Key"]||e[t]}function m(e){return({left:"right",right:"left",top:"bottom",bottom:"top"})[e]}function v(e,r){var t,a=function(e){var r=e.series,t=r.options.data||[],a=r.options.dragDrop.groupBy,o=[];if(r.boosted)for(var i=0,n=t.length;i<n;++i)o.push(new r.pointClass(r,t[i])),o[o.length-1].index=i;else o=r.points;return e.options[a]?o.filter(function(r){return r.options[a]===e.options[a]}):[e]}(r),o=r.series,i=o.chart;u(o.options.dragDrop&&o.options.dragDrop.liveRedraw,!0)||(i.dragGuideBox=t=o.getGuideBox(a),i.setGuideBoxState("default",o.options.dragDrop.guideBox).add(o.group)),i.dragDropData={origin:function(e,r,t){for(var a={chartX:e.chartX,chartY:e.chartY,guideBox:t&&{x:t.attr("x"),y:t.attr("y"),width:t.attr("width"),height:t.attr("height")},points:{}},o=0;o<r.length;o++){for(var i=r[o],n=i.series.dragDropProps||{},s={},d=0,g=Object.keys(n);d<g.length;d++){var p=g[d],l=n[p],h=i.series[l.axis+"Axis"];s[p]=i[p],i.series.chart.mapView&&i.plotX&&i.plotY?s[p+"Offset"]="x"===p?i.plotX:i.plotY:s[p+"Offset"]=h.toPixels(i[p])-(h.horiz?e.chartX:e.chartY)}s.point=i,a.points[i.id]=s}return a}(e,a,t),point:r,groupedPoints:a,isDragging:!0}}function D(e,r){var t=r.dragDropData;if(t&&t.isDragging&&t.draggedPastSensitivity&&t.point.series){var a=t.point,o=t.newPoints,i=s(o),n=1===i?d(o):null;r.dragHandles&&r.hideDragHandles(),e.preventDefault(),r.cancelClick=!0,a.firePointEvent("drop",{origin:t.origin,chartX:e.chartX,chartY:e.chartY,newPoints:o,numNewPoints:i,newPoint:n&&n.newValues,newPointId:n&&n.point.id},function(){P(r)})}delete r.dragDropData,r.dragGuideBox&&(r.dragGuideBox.destroy(),delete r.dragGuideBox)}function y(){if(!this.hasAddedDragDropEvents){var e,r;e=this,r=e.container,function(e){var r=e.series?e.series.length:0;if(e.hasCartesianSeries&&!e.polar||e.mapView){for(;r--;)if(e.series[r].options.dragDrop&&function(e){for(var r,t=["draggableX","draggableY"],a=e.dragDropProps||{},o=0,i=Object.keys(a);o<i.length;o++)(r=a[i[o]]).optionName&&t.push(r.optionName);for(var n=t.length;n--;)if(e.options.dragDrop[t[n]])return!0}(e.series[r]))return!0}return!1}(e)&&(n(r,["mousedown","touchstart"],function(r){(function(e,r){var t=r.hoverPoint,a=h(t&&t.series.options.dragDrop,t&&t.options.dragDrop),o=a.draggableX||!1,i=a.draggableY||!1;if(r.cancelClick=!1,!(!(o||i)||r.zoomOrPanKeyPressed(e))&&!r.hasDraggedAnnotation){if(r.dragDropData&&r.dragDropData.isDragging){D(e,r);return}t&&function(e){var r,t,a,o=e.series,i=o.chart,n=o.options.dragDrop||{},s=e.options&&e.options.dragDrop,d=o.dragDropProps;for(var g in d)"x"===(r=d[g]).axis&&r.move?t=!0:"y"===r.axis&&r.move&&(a=!0);return(n.draggableX&&t||n.draggableY&&a)&&!(s&&!1===s.draggableX&&!1===s.draggableY)&&(!!(o.yAxis&&o.xAxis)||i.mapView)}(t)&&(r.mouseIsDown=!1,v(e,t),t.firePointEvent("dragStart",e))}})(g(r,e),e)}),n(r,["mousemove","touchmove"],function(r){(function(e,r){if(!r.zoomOrPanKeyPressed(e)){var a,o,i,n,g,p,l,c,x,f,v=r.dragDropData,D=0;v&&v.isDragging&&v.point.series&&(c=(l=v.point).series.options.dragDrop,e.preventDefault(),v.draggedPastSensitivity||(v.draggedPastSensitivity=(a=u(l.options.dragDrop&&l.options.dragDrop.dragSensitivity,c&&c.dragSensitivity,t.dragSensitivity),i=(o=r.dragDropData.origin).chartX,n=o.chartY,Math.sqrt(((g=e.chartX)-i)*(g-i)+((p=e.chartY)-n)*(p-n))>a)),v.draggedPastSensitivity&&(v.newPoints=function(e,r){var t=e.point,a=t.series,o=a.chart,i=h(a.options.dragDrop,t.options.dragDrop),n={},s=e.updateProp,d={},g=t.series.dragDropProps;for(var p in g){var l=g[p];(!s||s===p&&l.resize&&(!l.optionName||!1!==i[l.optionName]))&&(s||l.move&&("x"===l.axis&&i.draggableX||"y"===l.axis&&i.draggableY))&&(o.mapView?n["x"===p?"lon":"lat"]=l:n[p]=l)}for(var u=0,c=s?[t]:e.groupedPoints;u<c.length;u++){var x=c[u];d[x.id]={point:x,newValues:x.getDropValues(e.origin,r,n)}}return d}(v,e),f=1===(D=s(x=v.newPoints))?d(x):null,l.firePointEvent("drag",{origin:v.origin,newPoints:v.newPoints,newPoint:f&&f.newValues,newPointId:f&&f.point.id,numNewPoints:D,chartX:e.chartX,chartY:e.chartY},function(){var r,t,a,o,i,n,s,d,g,p,c,x,f,v,D,y,b,w,z;a=(t=(r=l.series).chart).dragDropData,i=(o=h(r.options.dragDrop,l.options.dragDrop)).draggableX,n=o.draggableY,s=a.origin,d=a.updateProp,g=e.chartX-s.chartX,p=e.chartY-s.chartY,c=g,t.inverted&&(g=-p,p=-c),u(o.liveRedraw,!0)?(P(t,!1),l.showDragHandles()):d?(x=g,f=p,y=(D=(v=l.series).chart).dragDropData,b=v.dragDropProps[y.updateProp],w=y.newPoints[l.id].newValues,z="function"==typeof b.resizeSide?b.resizeSide(w,l):b.resizeSide,b.beforeResize&&b.beforeResize(D.dragGuideBox,w,l),function(e,r,t){var a;switch(r){case"left":a={x:e.attr("x")+t.x,width:Math.max(1,e.attr("width")-t.x)};break;case"right":a={width:Math.max(1,e.attr("width")+t.x)};break;case"top":a={y:e.attr("y")+t.y,height:Math.max(1,e.attr("height")-t.y)};break;case"bottom":a={height:Math.max(1,e.attr("height")+t.y)}}e.attr(a)}(D.dragGuideBox,"x"===b.axis&&v.xAxis.reversed||"y"===b.axis&&v.yAxis.reversed?m(z):z,{x:"x"===b.axis?x-(y.origin.prevdX||0):0,y:"y"===b.axis?f-(y.origin.prevdY||0):0})):t.dragGuideBox.translate(i?g:0,n?p:0),s.prevdX=g,s.prevdY=p})))}})(g(r,e),e)},{passive:!1}),l(r,"mouseleave",function(r){D(g(r,e),e)}),e.unbindDragDropMouseUp=n(p,["mouseup","touchend"],function(r){D(g(r,e),e)},{passive:!1}),e.hasAddedDragDropEvents=!0,l(e,"destroy",function(){e.unbindDragDropMouseUp&&e.unbindDragDropMouseUp()}))}}function P(e,r){var t,a=e.dragDropData.newPoints,o=i(r);e.isDragDropAnimating=!0;for(var n=0,s=Object.keys(a);n<s.length;n++)(t=a[s[n]]).point.update(t.newValues,!1);e.redraw(o),setTimeout(function(){delete e.isDragDropAnimating,e.hoverPoint&&!e.dragHandles&&e.hoverPoint.showDragHandles()},o.duration)}return{compose:function(e){var r=e.prototype;r.hideDragHandles||(r.hideDragHandles=c,r.setGuideBoxState=x,r.zoomOrPanKeyPressed=f,l(e,"render",y))},flipResizeSide:m,initDragDrop:v}}),t(r,"Extensions/DraggablePoints/DragDropProps.js",[r["Extensions/DraggablePoints/DraggableChart.js"],r["Core/Utilities.js"]],function(e,r){var t=this&&this.__assign||function(){return(t=Object.assign||function(e){for(var r,t=1,a=arguments.length;t<a;t++)for(var o in r=arguments[t])Object.prototype.hasOwnProperty.call(r,o)&&(e[o]=r[o]);return e}).apply(this,arguments)},a=e.flipResizeSide,o=r.isNumber,i=r.merge,n=r.pick,s={x:{axis:"x",move:!0},y:{axis:"y",move:!0}},d={x:{axis:"x",move:!0},y:{axis:"y",move:!1,resize:!0,beforeResize:function(e,r,t){var a,i,s=n(t.yBottom,t.series.translatedThreshold),d=e.attr("y"),g=o(t.stackY)?t.stackY-(t.y||0):t.series.options.threshold||0,p=g+r.y;(t.series.yAxis.reversed?p<g:p>=g)?(a=e.attr("height"),i=s?s-d-a:0,e.attr({height:Math.max(0,Math.round(a+i))})):e.attr({y:Math.round(d+(s?s-d:0))})},resizeSide:function(e,r){var t=r.series.chart.dragHandles,o=e.y>=(r.series.options.threshold||0)?"top":"bottom",i=a(o);return t&&t[i]&&(t[i].destroy(),delete t[i]),o},handlePositioner:function(e){var r=e.shapeArgs||e.graphic&&e.graphic.getBBox()||{},t=e.series.yAxis.reversed,a=e.series.options.threshold||0,o=e.y||0;return{x:r.x||0,y:!t&&o>=a||t&&o<a?r.y||0:(r.y||0)+(r.height||0)}},handleFormatter:function(e){var r=e.shapeArgs||{},t=r.r||0,a=r.width||0,o=a/2;return[["M",t,0],["L",o-5,0],["A",1,1,0,0,0,o+5,0],["A",1,1,0,0,0,o-5,0],["M",o+5,0],["L",a-t,0]]}}},g={x:d.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:function(e){return{x:e.shapeArgs.x||0,y:e.lowPlot}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.q1}},q1:{optionName:"draggableQ1",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:function(e){return{x:e.shapeArgs.x||0,y:e.q1Plot}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.median&&e>=r.low}},median:{axis:"y",move:!0},q3:{optionName:"draggableQ3",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){return{x:e.shapeArgs.x||0,y:e.q3Plot}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.high&&e>=r.median}},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){return{x:e.shapeArgs.x||0,y:e.highPlot}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e>=r.q3}}},p={x:d.x,low:t(t({},g.low),{propValidate:function(e,r){return e<=r.high}}),high:t(t({},g.high),{propValidate:function(e,r){return e>=r.low}})},l={x:d.x,y:d.y,target:{optionName:"draggableTarget",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){var r=e.targetGraphic.getBBox();return{x:e.barX,y:r.y+r.height/2}},handleFormatter:d.y.handleFormatter}},h={x:d.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:function(e){return{x:e.shapeArgs.x,y:e.plotLow}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.open&&e<=r.close}},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){return{x:e.shapeArgs.x,y:e.plotHigh}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e>=r.open&&e>=r.close}},open:{optionName:"draggableOpen",axis:"y",move:!0,resize:!0,resizeSide:function(e){return e.open>=e.close?"top":"bottom"},handlePositioner:function(e){return{x:e.shapeArgs.x,y:e.plotOpen}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.high&&e>=r.low}},close:{optionName:"draggableClose",axis:"y",move:!0,resize:!0,resizeSide:function(e){return e.open>=e.close?"bottom":"top"},handlePositioner:function(e){return{x:e.shapeArgs.x,y:e.plotClose}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.high&&e>=r.low}}},u={x:d.x,y:i(d.y,{handleFormatter:function(e){return e.isSum||e.isIntermediateSum?null:d.y.handleFormatter(e)}})},c={x:{axis:"x",move:!0},low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:function(e){var r=e.shapeArgs||e.graphic.getBBox();return{x:r.x||0,y:(r.y||0)+(r.height||0)}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e<=r.high}},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){var r=e.shapeArgs||e.graphic.getBBox();return{x:r.x||0,y:r.y||0}},handleFormatter:d.y.handleFormatter,propValidate:function(e,r){return e>=r.low}}},x={x:c.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:function(e){var r=e.graphics&&e.graphics[0]&&e.graphics[0].getBBox();return r?{x:r.x+r.width/2,y:r.y+r.height/2}:{x:-999,y:-999}},handleFormatter:m,propValidate:c.low.propValidate},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:function(e){var r=e.graphics&&e.graphics[1]&&e.graphics[1].getBBox();return r?{x:r.x+r.width/2,y:r.y+r.height/2}:{x:-999,y:-999}},handleFormatter:m,propValidate:c.high.propValidate}},f={y:{axis:"y",move:!0},x:{optionName:"draggableX1",axis:"x",move:!0,resize:!0,resizeSide:"left",handlePositioner:function(e){return D(e,"x")},handleFormatter:v,propValidate:function(e,r){return e<=r.x2}},x2:{optionName:"draggableX2",axis:"x",move:!0,resize:!0,resizeSide:"right",handlePositioner:function(e){return D(e,"x2")},handleFormatter:v,propValidate:function(e,r){return e>=r.x}}};function m(e){var r=e.graphic?e.graphic.getBBox().width/2+1:4;return[["M",0-r,0],["a",r,r,0,1,0,2*r,0],["a",r,r,0,1,0,-2*r,0]]}function v(e){var r=e.shapeArgs||e.graphic.getBBox(),t=r.r||0,a=r.height-t,o=r.height/2;return[["M",0,t],["L",0,o-5],["A",1,1,0,0,0,0,o+5],["A",1,1,0,0,0,0,o-5],["M",0,o+5],["L",0,a]]}function D(e,r){var t=e.series,a=t.xAxis,o=t.yAxis,i=t.chart.inverted,n=t.columnMetrics?t.columnMetrics.offset:-e.shapeArgs.height/2,s=a.toPixels(e[r],!0),d=o.toPixels(e.y,!0);return i&&(s=a.len-s,d=o.len-d),{x:Math.round(s),y:Math.round(d+=n)}}return{arearange:x,boxplot:g,bullet:l,column:d,columnrange:c,errorbar:p,flags:s,gantt:{y:f.y,start:i(f.x,{optionName:"draggableStart",validateIndividualDrag:function(e){return!e.milestone}}),end:i(f.x2,{optionName:"draggableEnd",validateIndividualDrag:function(e){return!e.milestone}})},line:s,ohlc:h,waterfall:u,xrange:f}}),t(r,"Extensions/DraggablePoints/DraggablePoints.js",[r["Extensions/DraggablePoints/DragDropUtilities.js"],r["Extensions/DraggablePoints/DraggableChart.js"],r["Extensions/DraggablePoints/DragDropDefaults.js"],r["Extensions/DraggablePoints/DragDropProps.js"],r["Core/Utilities.js"]],function(e,r,t,a,o){var i=e.addEvents,n=e.getNormalizedEvent,s=r.initDragDrop,d=o.addEvent,g=o.clamp,p=o.isNumber,l=o.merge,h=o.pick;function u(e){var r=e.series&&e.series.chart,t=r&&r.dragDropData;r&&r.dragHandles&&!(t&&(t.isDragging&&t.draggedPastSensitivity||t.isHoveringHandle===e.id))&&r.hideDragHandles()}function c(){var e=this;setTimeout(function(){e.series&&u(e)},10)}function x(){var e=this;setTimeout(function(){var r,t,a,o;return a=(t=(r=e.series)&&r.chart)&&t.dragDropData,o=t&&t.is3d&&t.is3d(),void(!t||a&&a.isDragging&&a.draggedPastSensitivity||t.isDragDropAnimating||!r.options.dragDrop||o||(t.dragHandles&&t.hideDragHandles(),e.showDragHandles()))},12)}function f(){var e=this.series.chart,r=e.dragHandles;r&&r.point===this.id&&e.hideDragHandles()}function m(e,r,t){for(var a=this.series,o=a.chart,i=o.mapView,n=l(a.options.dragDrop,this.options.dragDrop),s={},d=e.points[this.id],u=1===Object.keys(t).length,c=0,x=Object.keys(t);c<x.length;c++){var f=x[c],m=t[f],v=d.point[f],D=a[m.axis+"Axis"],y=i?function(e,r,t){if(i){var a=h(n["dragPrecision"+r],0),s=i.pixelsToLonLat({x:0,y:0}),d=i.pixelsToLonLat({x:o.plotBox.width,y:o.plotBox.height}),p=h(n["dragMin"+r],s&&s[t],-1/0),l=h(n["dragMax"+r],d&&d[t],1/0),u=e[t];if("Orthographic"===i.projection.options.name)return u;if("lat"===t){(isNaN(p)||p>i.projection.maxLatitude)&&(p=i.projection.maxLatitude),(isNaN(l)||l<-1*i.projection.maxLatitude)&&(l=-1*i.projection.maxLatitude);var c=l;l=p,p=c}if(!i.projection.hasCoordinates){var x=i.pixelsToLonLat({x:e.chartX-o.plotLeft,y:o.plotHeight-e.chartY+o.plotTop});x&&(u=x[t])}return a&&(u=Math.round(u/a)*a),g(u,p,l)}}(r,m.axis.toUpperCase(),f):function(e,r){var t=a[r.toLowerCase()+"Axis"].categories?1:0,o=h(n["dragPrecision"+r],t),i=h(n["dragMin"+r],-1/0),s=h(n["dragMax"+r],1/0),d=e;return o&&(d=Math.round(d/o)*o),g(d,i,s)}(D.toValue((D.horiz?r.chartX:r.chartY)+d[f+"Offset"]),m.axis.toUpperCase());p(y)&&!(u&&m.propValidate&&!m.propValidate(y,this))&&void 0!==v&&(s[f]=y)}return s}function v(){for(var e=this,r=e.series,a=r.chart,o=a.inverted,g=a.renderer,p=l(r.options.dragDrop,e.options.dragDrop),h=r.dragDropProps||{},c=a.dragHandles,x=function(x){var f=h[x],m=l(t.dragHandle,f.handleOptions,p.dragHandle),v={class:m.className,"stroke-width":m.lineWidth,fill:m.color,stroke:m.lineColor},D=m.pathFormatter||f.handleFormatter,y=f.handlePositioner,P=!f.validateIndividualDrag||f.validateIndividualDrag(e),b=void 0,w=void 0,z=void 0;if(f.resize&&P&&f.resizeSide&&D&&(p["draggable"+f.axis.toUpperCase()]||p[f.optionName])&&!1!==p[f.optionName]){c?c.point=e.id:c=a.dragHandles={group:g.g("drag-drop-handles").add(r.markerGroup||r.group),point:e.id},b=y(e),v.d=z=D(e);var A=e.series.xAxis.categories?-.5:0;if(!z||b.x<A||b.y<0)return{value:void 0};v.cursor=m.cursor||("x"===f.axis!=!!o?"ew-resize":"ns-resize"),(w=c[f.optionName])||(w=c[f.optionName]=g.path().add(c.group)),v.translateX=o?r.yAxis.len-b.y:b.x,v.translateY=o?r.xAxis.len-b.x:b.y,o&&(v.rotation=-90),w.attr(v),i(w.element,["touchstart","mousedown"],function(r){var t,o;t=n(r,a),(o=e.series.chart).zoomOrPanKeyPressed(t)||(o.mouseIsDown=!1,s(t,e),o.dragDropData.updateProp=t.updateProp=x,e.firePointEvent("dragStart",t),t.stopPropagation(),t.preventDefault())},{passive:!1}),d(c.group.element,"mouseover",function(){a.dragDropData=a.dragDropData||{},a.dragDropData.isHoveringHandle=e.id}),i(c.group.element,["touchend","mouseout"],function(){var r;(r=e.series.chart).dragDropData&&e.id===r.dragDropData.isHoveringHandle&&delete r.dragDropData.isHoveringHandle,r.hoverPoint||u(e)})}},f=0,m=Object.keys(h);f<m.length;f++){var v=x(m[f]);if("object"==typeof v)return v.value}}function D(e){for(var r,t=this.chart,a=1/0,o=-1/0,i=1/0,n=-1/0,s=0;s<e.length;s++){var d=e[s],g=d.graphic&&d.graphic.getBBox()||d.shapeArgs;if(g){var l=void 0,h=d.x2;p(h)&&(l=d.series.xAxis.translate(h,!1,!1,!1,!0));var u=!(g.width||g.height||g.x||g.y);r=!0,a=Math.min(d.plotX||0,l||0,u?1/0:g.x||0,a),o=Math.max(d.plotX||0,l||0,(g.x||0)+(g.width||0),o),i=Math.min(d.plotY||0,u?1/0:g.y||0,i),n=Math.max((g.y||0)+(g.height||0),n)}}return r?t.renderer.rect(a,i,o-a,n-i):t.renderer.g()}return{compose:function(e,t){r.compose(e);var o=t.prototype;if(!o.dragDropProps){var i=t.prototype.pointClass,n=t.types,s=i.prototype;s.getDropValues=m,s.showDragHandles=v,d(i,"mouseOut",c),d(i,"mouseOver",x),d(i,"remove",f),o.dragDropProps=a.line,o.getGuideBox=D;for(var g=0,p=["arearange","boxplot","bullet","column","columnrange","errorbar","flags","gantt","ohlc","waterfall","xrange"];g<p.length;g++){var l=p[g];n[l]&&(n[l].prototype.dragDropProps=a[l])}for(var h=0,u=["bellcurve","gauge","histogram","map","mapline","pareto","pie","sankey","sma","sunburst","treemap","vector","windbarb","wordcloud"];h<u.length;h++){var l=u[h];n[l]&&(n[l].prototype.dragDropProps=null)}}}}}),t(r,"masters/modules/draggable-points.src.js",[r["Core/Globals.js"],r["Extensions/DraggablePoints/DraggablePoints.js"]],function(e,r){return r.compose(e.Chart,e.Series),e})});