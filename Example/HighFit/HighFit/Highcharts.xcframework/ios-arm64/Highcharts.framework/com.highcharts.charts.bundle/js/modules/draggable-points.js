!/**
 * Highcharts JS v11.4.5 (2024-07-04)
 *
 * (c) 2009-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/draggable-points",["highcharts"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function r(t,r,o,a){t.hasOwnProperty(r)||(t[r]=a.apply(null,o),"function"==typeof CustomEvent&&e.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:r,module:t[r]}})))}r(t,"Extensions/DraggablePoints/DragDropUtilities.js",[t["Core/Utilities.js"]],function(e){let{addEvent:t}=e;return{addEvents:function(e,r,o,a){let i=r.map(r=>t(e,r,o,a));return function(){for(let e of i)e()}},countProps:function(e){return Object.keys(e).length},getFirstProp:function(e){for(let t in e)if(Object.hasOwnProperty.call(e,t))return e[t]},getNormalizedEvent:function(e,t){return(void 0===e.chartX||void 0===e.chartY)&&t.pointer?.normalize(e)||e}}}),r(t,"Extensions/DraggablePoints/DragDropDefaults.js",[],function(){return{dragSensitivity:2,dragHandle:{className:"highcharts-drag-handle",color:"#fff",lineColor:"rgba(0, 0, 0, 0.6)",lineWidth:1,zIndex:901},guideBox:{default:{className:"highcharts-drag-box-default",lineWidth:1,lineColor:"#888",color:"rgba(0, 0, 0, 0.1)",cursor:"move",zIndex:900}}}}),r(t,"Extensions/DraggablePoints/DraggableChart.js",[t["Core/Animation/AnimationUtilities.js"],t["Extensions/DraggablePoints/DragDropUtilities.js"],t["Extensions/DraggablePoints/DragDropDefaults.js"],t["Core/Globals.js"],t["Core/Utilities.js"]],function(e,t,r,o,a){let{animObject:i}=e,{addEvents:s,countProps:n,getFirstProp:d,getNormalizedEvent:l}=t,{doc:g}=o,{addEvent:p,merge:h,pick:u}=a;function x(){let e=this.dragHandles||{};if(e){for(let t of Object.keys(e))e[t].destroy&&e[t].destroy();delete this.dragHandles}}function c(e,t){let o=this.dragGuideBox,a=h(r.guideBox,t),i=h(a.default,a[e]);return o.attr({class:i.className,stroke:i.lineColor,strokeWidth:i.lineWidth,fill:i.color,cursor:i.cursor,zIndex:i.zIndex}).css({pointerEvents:"none"})}function m(e){let t=this.options.chart||{},r=t.panKey&&t.panKey+"Key";return e[this.zooming.key&&this.zooming.key+"Key"]||e[r]}function f(e){return({left:"right",right:"left",top:"bottom",bottom:"top"})[e]}function D(e,t){let r;let o=function(e){let t=e.series,r=t.options.data||[],o=t.options.dragDrop.groupBy,a=[];if(t.boosted)for(let e=0,o=r.length;e<o;++e)a.push(new t.pointClass(t,r[e])),a[a.length-1].index=e;else a=t.points;return e.options[o]?a.filter(t=>t.options[o]===e.options[o]):[e]}(t),a=t.series,i=a.chart;u(a.options.dragDrop&&a.options.dragDrop.liveRedraw,!0)||(i.dragGuideBox=r=a.getGuideBox(o),i.setGuideBoxState("default",a.options.dragDrop.guideBox).add(a.group)),i.dragDropData={origin:function(e,t,r){let o={chartX:e.chartX,chartY:e.chartY,guideBox:r&&{x:r.attr("x"),y:r.attr("y"),width:r.attr("width"),height:r.attr("height")},points:{}};for(let r of t){let t=r.series.dragDropProps||{},a={};for(let o of Object.keys(t)){let i=t[o],s=r.series[i.axis+"Axis"];a[o]=r[o],r.series.chart.mapView&&r.plotX&&r.plotY?a[o+"Offset"]="x"===o?r.plotX:r.plotY:a[o+"Offset"]=s.toPixels(r[o])-(s.horiz?e.chartX:e.chartY)}a.point=r,o.points[r.id]=a}return o}(e,o,r),point:t,groupedPoints:o,isDragging:!0}}function y(e,t){let r=t.dragDropData;if(r&&r.isDragging&&r.draggedPastSensitivity&&r.point.series){let o=r.point,a=r.newPoints,i=n(a),s=1===i?d(a):null;t.dragHandles&&t.hideDragHandles(),e.preventDefault(),t.cancelClick=!0,o.firePointEvent("drop",{origin:r.origin,chartX:e.chartX,chartY:e.chartY,newPoints:a,numNewPoints:i,newPoint:s&&s.newValues,newPointId:s&&s.point.id},function(){v(t)})}delete t.dragDropData,t.dragGuideBox&&(t.dragGuideBox.destroy(),delete t.dragGuideBox)}function P(){this.hasAddedDragDropEvents||function(e){let t=e.container;(function(e){let t=e.series?e.series.length:0;if(e.hasCartesianSeries&&!e.polar||e.mapView){for(;t--;)if(e.series[t].options.dragDrop&&function(e){let t;let r=["draggableX","draggableY"],o=e.dragDropProps||{};for(let e of Object.keys(o))(t=o[e]).optionName&&r.push(t.optionName);let a=r.length;for(;a--;)if(e.options.dragDrop[r[a]])return!0}(e.series[t]))return!0}return!1})(e)&&(s(t,["mousedown","touchstart"],t=>{(function(e,t){let r=t.hoverPoint,o=h(r&&r.series.options.dragDrop,r&&r.options.dragDrop),a=o.draggableX||!1,i=o.draggableY||!1;if(t.cancelClick=!1,!(!(a||i)||t.zoomOrPanKeyPressed(e))&&!t.hasDraggedAnnotation){if(t.dragDropData&&t.dragDropData.isDragging){y(e,t);return}r&&function(e){let t,r,o;let a=e.series,i=a.chart,s=a.options.dragDrop||{},n=e.options&&e.options.dragDrop,d=a.dragDropProps;for(let e in d)"x"===(t=d[e]).axis&&t.move?r=!0:"y"===t.axis&&t.move&&(o=!0);return(s.draggableX&&r||s.draggableY&&o)&&!(n&&!1===n.draggableX&&!1===n.draggableY)&&(!!(a.yAxis&&a.xAxis)||i.mapView)}(r)&&(t.mouseIsDown=!1,D(e,r),r.firePointEvent("dragStart",e))}})(l(t,e),e)}),s(t,["mousemove","touchmove"],t=>{(function(e,t){if(t.zoomOrPanKeyPressed(e))return;let o=t.dragDropData,a,i,s,l=0,g;o&&o.isDragging&&o.point.series&&(i=(a=o.point).series.options.dragDrop,e.preventDefault(),o.draggedPastSensitivity||(o.draggedPastSensitivity=function(e,t,r){let o=t.dragDropData.origin,a=o.chartX,i=o.chartY,s=e.chartX,n=e.chartY;return Math.sqrt((s-a)*(s-a)+(n-i)*(n-i))>r}(e,t,u(a.options.dragDrop&&a.options.dragDrop.dragSensitivity,i&&i.dragSensitivity,r.dragSensitivity))),o.draggedPastSensitivity&&(o.newPoints=function(e,t){let r=e.point,o=r.series,a=o.chart,i=h(o.options.dragDrop,r.options.dragDrop),s={},n=e.updateProp,d={},l=r.series.dragDropProps;for(let e in l){let t=l[e];(!n||n===e&&t.resize&&(!t.optionName||!1!==i[t.optionName]))&&(n||t.move&&("x"===t.axis&&i.draggableX||"y"===t.axis&&i.draggableY))&&(a.mapView?s["x"===e?"lon":"lat"]=t:s[e]=t)}for(let o of n?[r]:e.groupedPoints)d[o.id]={point:o,newValues:o.getDropValues(e.origin,t,s)};return d}(o,e),g=1===(l=n(s=o.newPoints))?d(s):null,a.firePointEvent("drag",{origin:o.origin,newPoints:o.newPoints,newPoint:g&&g.newValues,newPointId:g&&g.point.id,numNewPoints:l,chartX:e.chartX,chartY:e.chartY},function(){!function(e,t){let r=t.series,o=r.chart,a=o.dragDropData,i=h(r.options.dragDrop,t.options.dragDrop),s=i.draggableX,n=i.draggableY,d=a.origin,l=a.updateProp,g=e.chartX-d.chartX,p=e.chartY-d.chartY,x=g;o.inverted&&(g=-p,p=-x),u(i.liveRedraw,!0)?(v(o,!1),t.showDragHandles()):l?function(e,t,r){let o=e.series,a=o.chart,i=a.dragDropData,s=o.dragDropProps[i.updateProp],n=i.newPoints[e.id].newValues,d="function"==typeof s.resizeSide?s.resizeSide(n,e):s.resizeSide;s.beforeResize&&s.beforeResize(a.dragGuideBox,n,e),function(e,t,r){let o;switch(t){case"left":o={x:e.attr("x")+r.x,width:Math.max(1,e.attr("width")-r.x)};break;case"right":o={width:Math.max(1,e.attr("width")+r.x)};break;case"top":o={y:e.attr("y")+r.y,height:Math.max(1,e.attr("height")-r.y)};break;case"bottom":o={height:Math.max(1,e.attr("height")+r.y)}}e.attr(o)}(a.dragGuideBox,"x"===s.axis&&o.xAxis.reversed||"y"===s.axis&&o.yAxis.reversed?f(d):d,{x:"x"===s.axis?t-(i.origin.prevdX||0):0,y:"y"===s.axis?r-(i.origin.prevdY||0):0})}(t,g,p):o.dragGuideBox.translate(s?g:0,n?p:0),d.prevdX=g,d.prevdY=p}(e,a)})))})(l(t,e),e)},{passive:!1}),p(t,"mouseleave",t=>{y(l(t,e),e)}),e.unbindDragDropMouseUp=s(g,["mouseup","touchend"],t=>{y(l(t,e),e)},{passive:!1}),e.hasAddedDragDropEvents=!0,p(e,"destroy",()=>{e.unbindDragDropMouseUp&&e.unbindDragDropMouseUp()}))}(this)}function v(e,t){let r;let o=e.dragDropData.newPoints,a=i(t);for(let t of(e.isDragDropAnimating=!0,Object.keys(o)))(r=o[t]).point.update(r.newValues,!1);e.redraw(a),setTimeout(()=>{delete e.isDragDropAnimating,e.hoverPoint&&!e.dragHandles&&e.hoverPoint.showDragHandles()},a.duration)}return{compose:function(e){let t=e.prototype;t.hideDragHandles||(t.hideDragHandles=x,t.setGuideBoxState=c,t.zoomOrPanKeyPressed=m,p(e,"render",P))},flipResizeSide:f,initDragDrop:D}}),r(t,"Extensions/DraggablePoints/DragDropProps.js",[t["Extensions/DraggablePoints/DraggableChart.js"],t["Core/Utilities.js"]],function(e,t){let{flipResizeSide:r}=e,{isNumber:o,merge:a,pick:i}=t,s={x:{axis:"x",move:!0},y:{axis:"y",move:!0}},n={x:{axis:"x",move:!0},y:{axis:"y",move:!1,resize:!0,beforeResize:(e,t,r)=>{let a,s;let n=i(r.yBottom,r.series.translatedThreshold),d=e.attr("y"),l=o(r.stackY)?r.stackY-(r.y||0):r.series.options.threshold||0,g=l+t.y;(r.series.yAxis.reversed?g<l:g>=l)?(a=e.attr("height"),s=n?n-d-a:0,e.attr({height:Math.max(0,Math.round(a+s))})):e.attr({y:Math.round(d+(n?n-d:0))})},resizeSide:(e,t)=>{let o=t.series.chart.dragHandles,a=e.y>=(t.series.options.threshold||0)?"top":"bottom",i=r(a);return o&&o[i]&&(o[i].destroy(),delete o[i]),a},handlePositioner:e=>{let t=e.shapeArgs||e.graphic&&e.graphic.getBBox()||{},r=e.series.yAxis.reversed,o=e.series.options.threshold||0,a=e.y||0;return{x:t.x||0,y:!r&&a>=o||r&&a<o?t.y||0:(t.y||0)+(t.height||0)}},handleFormatter:e=>{let t=e.shapeArgs||{},r=t.r||0,o=t.width||0,a=o/2;return[["M",r,0],["L",a-5,0],["A",1,1,0,0,0,a+5,0],["A",1,1,0,0,0,a-5,0],["M",a+5,0],["L",o-r,0]]}}},d={x:n.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:e=>({x:e.shapeArgs.x||0,y:e.lowPlot}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.q1},q1:{optionName:"draggableQ1",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:e=>({x:e.shapeArgs.x||0,y:e.q1Plot}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.median&&e>=t.low},median:{axis:"y",move:!0},q3:{optionName:"draggableQ3",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>({x:e.shapeArgs.x||0,y:e.q3Plot}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.high&&e>=t.median},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>({x:e.shapeArgs.x||0,y:e.highPlot}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e>=t.q3}},l={x:n.x,low:{...d.low,propValidate:(e,t)=>e<=t.high},high:{...d.high,propValidate:(e,t)=>e>=t.low}},g={x:n.x,y:n.y,target:{optionName:"draggableTarget",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>{let t=e.targetGraphic.getBBox();return{x:e.barX,y:t.y+t.height/2}},handleFormatter:n.y.handleFormatter}},p={x:n.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:e=>({x:e.shapeArgs.x,y:e.plotLow}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.open&&e<=t.close},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>({x:e.shapeArgs.x,y:e.plotHigh}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e>=t.open&&e>=t.close},open:{optionName:"draggableOpen",axis:"y",move:!0,resize:!0,resizeSide:e=>e.open>=e.close?"top":"bottom",handlePositioner:e=>({x:e.shapeArgs.x,y:e.plotOpen}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.high&&e>=t.low},close:{optionName:"draggableClose",axis:"y",move:!0,resize:!0,resizeSide:e=>e.open>=e.close?"bottom":"top",handlePositioner:e=>({x:e.shapeArgs.x,y:e.plotClose}),handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.high&&e>=t.low}},h={x:n.x,y:a(n.y,{handleFormatter:e=>e.isSum||e.isIntermediateSum?null:n.y.handleFormatter(e)})},u={x:{axis:"x",move:!0},low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:e=>{let t=e.shapeArgs||e.graphic.getBBox();return{x:t.x||0,y:(t.y||0)+(t.height||0)}},handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e<=t.high},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>{let t=e.shapeArgs||e.graphic.getBBox();return{x:t.x||0,y:t.y||0}},handleFormatter:n.y.handleFormatter,propValidate:(e,t)=>e>=t.low}},x={x:u.x,low:{optionName:"draggableLow",axis:"y",move:!0,resize:!0,resizeSide:"bottom",handlePositioner:e=>{let t=e.graphics&&e.graphics[0]&&e.graphics[0].getBBox();return t?{x:t.x+t.width/2,y:t.y+t.height/2}:{x:-999,y:-999}},handleFormatter:m,propValidate:u.low.propValidate},high:{optionName:"draggableHigh",axis:"y",move:!0,resize:!0,resizeSide:"top",handlePositioner:e=>{let t=e.graphics&&e.graphics[1]&&e.graphics[1].getBBox();return t?{x:t.x+t.width/2,y:t.y+t.height/2}:{x:-999,y:-999}},handleFormatter:m,propValidate:u.high.propValidate}},c={y:{axis:"y",move:!0},x:{optionName:"draggableX1",axis:"x",move:!0,resize:!0,resizeSide:"left",handlePositioner:e=>D(e,"x"),handleFormatter:f,propValidate:(e,t)=>e<=t.x2},x2:{optionName:"draggableX2",axis:"x",move:!0,resize:!0,resizeSide:"right",handlePositioner:e=>D(e,"x2"),handleFormatter:f,propValidate:(e,t)=>e>=t.x}};function m(e){let t=e.graphic?e.graphic.getBBox().width/2+1:4;return[["M",0-t,0],["a",t,t,0,1,0,2*t,0],["a",t,t,0,1,0,-2*t,0]]}function f(e){let t=e.shapeArgs||e.graphic.getBBox(),r=t.r||0,o=t.height-r,a=t.height/2;return[["M",0,r],["L",0,a-5],["A",1,1,0,0,0,0,a+5],["A",1,1,0,0,0,0,a-5],["M",0,a+5],["L",0,o]]}function D(e,t){let r=e.series,o=r.xAxis,a=r.yAxis,i=r.chart.inverted,s=r.columnMetrics?r.columnMetrics.offset:-e.shapeArgs.height/2,n=o.toPixels(e[t],!0),d=a.toPixels(e.y,!0);return i&&(n=o.len-n,d=a.len-d),{x:Math.round(n),y:Math.round(d+=s)}}return{arearange:x,boxplot:d,bullet:g,column:n,columnrange:u,errorbar:l,flags:s,gantt:{y:c.y,start:a(c.x,{optionName:"draggableStart",validateIndividualDrag:e=>!e.milestone}),end:a(c.x2,{optionName:"draggableEnd",validateIndividualDrag:e=>!e.milestone})},line:s,ohlc:p,waterfall:h,xrange:c}}),r(t,"Extensions/DraggablePoints/DraggablePoints.js",[t["Extensions/DraggablePoints/DragDropUtilities.js"],t["Extensions/DraggablePoints/DraggableChart.js"],t["Extensions/DraggablePoints/DragDropDefaults.js"],t["Extensions/DraggablePoints/DragDropProps.js"],t["Core/Utilities.js"]],function(e,t,r,o,a){let{addEvents:i,getNormalizedEvent:s}=e,{initDragDrop:n}=t,{addEvent:d,clamp:l,isNumber:g,merge:p,pick:h}=a;function u(e){let t=e.series&&e.series.chart,r=t&&t.dragDropData;t&&t.dragHandles&&!(r&&(r.isDragging&&r.draggedPastSensitivity||r.isHoveringHandle===e.id))&&t.hideDragHandles()}function x(){let e=this;setTimeout(()=>{e.series&&u(e)},10)}function c(){let e=this;setTimeout(()=>(function(e){let t=e.series,r=t&&t.chart,o=r&&r.dragDropData,a=r&&r.is3d&&r.is3d();!r||o&&o.isDragging&&o.draggedPastSensitivity||r.isDragDropAnimating||!t.options.dragDrop||a||(r.dragHandles&&r.hideDragHandles(),e.showDragHandles())})(e),12)}function m(){let e=this.series.chart,t=e.dragHandles;t&&t.point===this.id&&e.hideDragHandles()}function f(e,t,r){let o=this.series,a=o.chart,i=a.mapView,s=p(o.options.dragDrop,this.options.dragDrop),n={},d=e.points[this.id],u=1===Object.keys(r).length,x=(e,t)=>{let r=o[t.toLowerCase()+"Axis"].categories?1:0,a=h(s["dragPrecision"+t],r),i=h(s["dragMin"+t],-1/0),n=h(s["dragMax"+t],1/0),d=e;return a&&(d=Math.round(d/a)*a),l(d,i,n)},c=(e,t,r)=>{if(i){let o=h(s["dragPrecision"+t],0),n=i.pixelsToLonLat({x:0,y:0}),d=i.pixelsToLonLat({x:a.plotBox.width,y:a.plotBox.height}),g=h(s["dragMin"+t],n&&n[r],-1/0),p=h(s["dragMax"+t],d&&d[r],1/0),u=e[r];if("Orthographic"===i.projection.options.name)return u;if("lat"===r){(isNaN(g)||g>i.projection.maxLatitude)&&(g=i.projection.maxLatitude),(isNaN(p)||p<-1*i.projection.maxLatitude)&&(p=-1*i.projection.maxLatitude);let e=p;p=g,g=e}if(!i.projection.hasCoordinates){let t=i.pixelsToLonLat({x:e.chartX-a.plotLeft,y:a.plotHeight-e.chartY+a.plotTop});t&&(u=t[r])}return o&&(u=Math.round(u/o)*o),l(u,g,p)}};for(let e of Object.keys(r)){let a=r[e],s=d.point[e],l=o[a.axis+"Axis"],p=i?c(t,a.axis.toUpperCase(),e):x(l.toValue((l.horiz?t.chartX:t.chartY)+d[e+"Offset"]),a.axis.toUpperCase());g(p)&&!(u&&a.propValidate&&!a.propValidate(p,this))&&void 0!==s&&(n[e]=p)}return n}function D(){let e=this,t=e.series,o=t.chart,{inverted:a,renderer:l}=o,g=p(t.options.dragDrop,e.options.dragDrop),h=t.dragDropProps||{},x=o.dragHandles;for(let c of Object.keys(h)){let m,f,D;let y=h[c],P=p(r.dragHandle,y.handleOptions,g.dragHandle),v={class:P.className,"stroke-width":P.lineWidth,fill:P.color,stroke:P.lineColor},b=P.pathFormatter||y.handleFormatter,w=y.handlePositioner,z=!y.validateIndividualDrag||y.validateIndividualDrag(e);if(y.resize&&z&&y.resizeSide&&b&&(g["draggable"+y.axis.toUpperCase()]||g[y.optionName])&&!1!==g[y.optionName]){x?x.point=e.id:x=o.dragHandles={group:l.g("drag-drop-handles").add(t.markerGroup||t.group),point:e.id},m=w(e),v.d=D=b(e);let r=e.series.xAxis.categories?-.5:0;if(!D||m.x<r||m.y<0)return;v.cursor=P.cursor||("x"===y.axis!=!!a?"ew-resize":"ns-resize"),(f=x[y.optionName])||(f=x[y.optionName]=l.path().add(x.group)),v.translateX=a?t.yAxis.len-m.y:m.x,v.translateY=a?t.xAxis.len-m.x:m.y,a&&(v.rotation=-90),f.attr(v),i(f.element,["touchstart","mousedown"],t=>{!function(e,t,r){let o=t.series.chart;o.zoomOrPanKeyPressed(e)||(o.mouseIsDown=!1,n(e,t),o.dragDropData.updateProp=e.updateProp=r,t.firePointEvent("dragStart",e),e.stopPropagation(),e.preventDefault())}(s(t,o),e,c)},{passive:!1}),d(x.group.element,"mouseover",()=>{o.dragDropData=o.dragDropData||{},o.dragDropData.isHoveringHandle=e.id}),i(x.group.element,["touchend","mouseout"],()=>{!function(e){let t=e.series.chart;t.dragDropData&&e.id===t.dragDropData.isHoveringHandle&&delete t.dragDropData.isHoveringHandle,t.hoverPoint||u(e)}(e)})}}}function y(e){let t=this.chart,r=1/0,o=-1/0,a=1/0,i=-1/0,s;for(let t of e){let e=t.graphic&&t.graphic.getBBox()||t.shapeArgs;if(e){let n;let d=t.x2;g(d)&&(n=t.series.xAxis.translate(d,!1,!1,!1,!0));let l=!(e.width||e.height||e.x||e.y);s=!0,r=Math.min(t.plotX||0,n||0,l?1/0:e.x||0,r),o=Math.max(t.plotX||0,n||0,(e.x||0)+(e.width||0),o),a=Math.min(t.plotY||0,l?1/0:e.y||0,a),i=Math.max((e.y||0)+(e.height||0),i)}}return s?t.renderer.rect(r,a,o-r,i-a):t.renderer.g()}return{compose:function(e,r){t.compose(e);let a=r.prototype;if(!a.dragDropProps){let e=r.prototype.pointClass,t=r.types,i=e.prototype;for(let r of(i.getDropValues=f,i.showDragHandles=D,d(e,"mouseOut",x),d(e,"mouseOver",c),d(e,"remove",m),a.dragDropProps=o.line,a.getGuideBox=y,["arearange","boxplot","bullet","column","columnrange","errorbar","flags","gantt","ohlc","waterfall","xrange"]))t[r]&&(t[r].prototype.dragDropProps=o[r]);for(let e of["bellcurve","gauge","histogram","map","mapline","pareto","pie","sankey","sma","sunburst","treemap","vector","windbarb","wordcloud"])t[e]&&(t[e].prototype.dragDropProps=null)}}}}),r(t,"masters/modules/draggable-points.src.js",[t["Core/Globals.js"],t["Extensions/DraggablePoints/DraggablePoints.js"]],function(e,t){return t.compose(e.Chart,e.Series),e})});