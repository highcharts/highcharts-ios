/*
 Highcharts JS v10.0.0 (2022-03-07)

 Force directed graph module

 (c) 2010-2021 Torstein Honsi

 License: www.highcharts.com/license
*/
(function(e){"object"===typeof module&&module.exports?(e["default"]=e,module.exports=e):"function"===typeof define&&define.amd?define("highcharts/modules/networkgraph",["highcharts"],function(k){e(k);e.Highcharts=k;return e}):e("undefined"!==typeof Highcharts?Highcharts:void 0)})(function(e){function k(e,b,a,g){e.hasOwnProperty(b)||(e[b]=g.apply(null,a),"function"===typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:b,module:e[b]}})))}e=e?e._modules:{};
k(e,"Series/NodesComposition.js",[e["Core/Series/Point.js"],e["Core/Series/Series.js"],e["Core/Utilities.js"]],function(e,b,a){var g=a.defined,d=a.extend,h=a.find,v=a.merge,l=a.pick,x;(function(a){function c(){this.data=[].concat(this.points||[],this.nodes);return b.prototype.destroy.apply(this,arguments)}function q(){this.nodes&&(this.nodes.forEach(function(c){c.destroy()}),this.nodes.length=0);b.prototype.setData.apply(this,arguments)}function u(c){var f=arguments,b=this.isNode?this.linksTo.concat(this.linksFrom):
[this.fromNode,this.toNode];"select"!==c&&b.forEach(function(c){c&&c.series&&(e.prototype.setState.apply(c,f),c.isNode||(c.fromNode.graphic&&e.prototype.setState.apply(c.fromNode,f),c.toNode&&c.toNode.graphic&&e.prototype.setState.apply(c.toNode,f)))});e.prototype.setState.apply(this,f)}function r(c,b,d,a){var f=this,g=this.series.options.nodes,m=this.series.options.data,w=m&&m.length||0,q=m&&m[this.index];e.prototype.update.call(this,c,this.isNode?!1:b,d,a);this.isNode&&(c=(g||[]).reduce(function(c,
b,a){return f.id===b.id?a:c},-1),a=v(g&&g[c]||{},m&&m[this.index]||{}),m&&(q?m[this.index]=q:m.length=w),g?0<=c?g[c]=a:g.push(a):this.series.options.nodes=[a],l(b,!0)&&this.series.chart.redraw(d))}var n=[];a.compose=function(f,b){-1===n.indexOf(f)&&(n.push(f),f=f.prototype,f.setNodeState=u,f.setState=u,f.update=r);-1===n.indexOf(b)&&(n.push(b),f=b.prototype,f.destroy=c,f.setData=q);return b};a.createNode=function(c){var b=this.pointClass,f=function(c,a){return h(c,function(c){return c.id===a})},a=
f(this.nodes,c);a||(f=this.options.nodes&&f(this.options.nodes,c),a=(new b).init(this,d({className:"highcharts-node",isNode:!0,id:c,y:1},f)),a.linksTo=[],a.linksFrom=[],a.getSum=function(){var c=0,f=0;a.linksTo.forEach(function(a){c+=a.weight});a.linksFrom.forEach(function(c){f+=c.weight});return Math.max(c,f)},a.offset=function(c,f){for(var b=0,d=0;d<a[f].length;d++){if(a[f][d]===c)return b;b+=a[f][d].weight}},a.hasShape=function(){var c=0;a.linksTo.forEach(function(a){a.outgoing&&c++});return!a.linksTo.length||
c!==a.linksTo.length},a.index=this.nodes.push(a)-1);a.formatPrefix="node";a.name=a.name||a.options.id||"";a.mass=l(a.options.mass,a.options.marker&&a.options.marker.radius,this.options.marker&&this.options.marker.radius,4);return a};a.destroy=c;a.generatePoints=function(){var c=this.chart,a={};b.prototype.generatePoints.call(this);this.nodes||(this.nodes=[]);this.colorCounter=0;this.nodes.forEach(function(c){c.linksFrom.length=0;c.linksTo.length=0;c.level=c.options.level});this.points.forEach(function(f){g(f.from)&&
(a[f.from]||(a[f.from]=this.createNode(f.from)),a[f.from].linksFrom.push(f),f.fromNode=a[f.from],c.styledMode?f.colorIndex=l(f.options.colorIndex,a[f.from].colorIndex):f.color=f.options.color||a[f.from].color);g(f.to)&&(a[f.to]||(a[f.to]=this.createNode(f.to)),a[f.to].linksTo.push(f),f.toNode=a[f.to]);f.name=f.name||f.id},this);this.nodeLookup=a};a.setNodeState=u;a.updateNode=r})(x||(x={}));return x});k(e,"Series/Networkgraph/Integrations.js",[e["Core/Globals.js"]],function(e){e.networkgraphIntegrations=
{verlet:{attractiveForceFunction:function(b,a){return(a-b)/b},repulsiveForceFunction:function(b,a){return(a-b)/b*(a>b?1:0)},barycenter:function(){var b=this.options.gravitationalConstant,a=this.barycenter.xFactor,g=this.barycenter.yFactor;a=(a-(this.box.left+this.box.width)/2)*b;g=(g-(this.box.top+this.box.height)/2)*b;this.nodes.forEach(function(b){b.fixedPosition||(b.plotX-=a/b.mass/b.degree,b.plotY-=g/b.mass/b.degree)})},repulsive:function(b,a,g){a=a*this.diffTemperature/b.mass/b.degree;b.fixedPosition||
(b.plotX+=g.x*a,b.plotY+=g.y*a)},attractive:function(b,a,g){var d=b.getMass(),h=-g.x*a*this.diffTemperature;a=-g.y*a*this.diffTemperature;b.fromNode.fixedPosition||(b.fromNode.plotX-=h*d.fromNode/b.fromNode.degree,b.fromNode.plotY-=a*d.fromNode/b.fromNode.degree);b.toNode.fixedPosition||(b.toNode.plotX+=h*d.toNode/b.toNode.degree,b.toNode.plotY+=a*d.toNode/b.toNode.degree)},integrate:function(b,a){var g=-b.options.friction,d=b.options.maxSpeed,h=(a.plotX+a.dispX-a.prevX)*g;g*=a.plotY+a.dispY-a.prevY;
var e=Math.abs,l=e(h)/(h||1);e=e(g)/(g||1);h=l*Math.min(d,Math.abs(h));g=e*Math.min(d,Math.abs(g));a.prevX=a.plotX+a.dispX;a.prevY=a.plotY+a.dispY;a.plotX+=h;a.plotY+=g;a.temperature=b.vectorLength({x:h,y:g})},getK:function(b){return Math.pow(b.box.width*b.box.height/b.nodes.length,.5)}},euler:{attractiveForceFunction:function(b,a){return b*b/a},repulsiveForceFunction:function(b,a){return a*a/b},barycenter:function(){var b=this.options.gravitationalConstant,a=this.barycenter.xFactor,g=this.barycenter.yFactor;
this.nodes.forEach(function(d){if(!d.fixedPosition){var h=d.getDegree();h*=1+h/2;d.dispX+=(a-d.plotX)*b*h/d.degree;d.dispY+=(g-d.plotY)*b*h/d.degree}})},repulsive:function(b,a,g,d){b.dispX+=g.x/d*a/b.degree;b.dispY+=g.y/d*a/b.degree},attractive:function(b,a,g,d){var h=b.getMass(),e=g.x/d*a;a*=g.y/d;b.fromNode.fixedPosition||(b.fromNode.dispX-=e*h.fromNode/b.fromNode.degree,b.fromNode.dispY-=a*h.fromNode/b.fromNode.degree);b.toNode.fixedPosition||(b.toNode.dispX+=e*h.toNode/b.toNode.degree,b.toNode.dispY+=
a*h.toNode/b.toNode.degree)},integrate:function(b,a){a.dispX+=a.dispX*b.options.friction;a.dispY+=a.dispY*b.options.friction;var g=a.temperature=b.vectorLength({x:a.dispX,y:a.dispY});0!==g&&(a.plotX+=a.dispX/g*Math.min(Math.abs(a.dispX),b.temperature),a.plotY+=a.dispY/g*Math.min(Math.abs(a.dispY),b.temperature))},getK:function(b){return Math.pow(b.box.width*b.box.height/b.nodes.length,.3)}}}});k(e,"Series/Networkgraph/QuadTree.js",[e["Core/Globals.js"],e["Core/Utilities.js"]],function(e,b){b=b.extend;
var a=e.QuadTreeNode=function(a){this.box=a;this.boxSize=Math.min(a.width,a.height);this.nodes=[];this.body=this.isInternal=!1;this.isEmpty=!0};b(a.prototype,{insert:function(b,d){this.isInternal?this.nodes[this.getBoxPosition(b)].insert(b,d-1):(this.isEmpty=!1,this.body?d?(this.isInternal=!0,this.divideBox(),!0!==this.body&&(this.nodes[this.getBoxPosition(this.body)].insert(this.body,d-1),this.body=!0),this.nodes[this.getBoxPosition(b)].insert(b,d-1)):(d=new a({top:b.plotX,left:b.plotY,width:.1,
height:.1}),d.body=b,d.isInternal=!1,this.nodes.push(d)):(this.isInternal=!1,this.body=b))},updateMassAndCenter:function(){var a=0,b=0,h=0;this.isInternal?(this.nodes.forEach(function(d){d.isEmpty||(a+=d.mass,b+=d.plotX*d.mass,h+=d.plotY*d.mass)}),b/=a,h/=a):this.body&&(a=this.body.mass,b=this.body.plotX,h=this.body.plotY);this.mass=a;this.plotX=b;this.plotY=h},divideBox:function(){var b=this.box.width/2,d=this.box.height/2;this.nodes[0]=new a({left:this.box.left,top:this.box.top,width:b,height:d});
this.nodes[1]=new a({left:this.box.left+b,top:this.box.top,width:b,height:d});this.nodes[2]=new a({left:this.box.left+b,top:this.box.top+d,width:b,height:d});this.nodes[3]=new a({left:this.box.left,top:this.box.top+d,width:b,height:d})},getBoxPosition:function(a){var b=a.plotY<this.box.top+this.box.height/2;return a.plotX<this.box.left+this.box.width/2?b?0:3:b?1:2}});e=e.QuadTree=function(b,d,h,e){this.box={left:b,top:d,width:h,height:e};this.maxDepth=25;this.root=new a(this.box,"0");this.root.isInternal=
!0;this.root.isRoot=!0;this.root.divideBox()};b(e.prototype,{insertNodes:function(a){a.forEach(function(a){this.root.insert(a,this.maxDepth)},this)},visitNodeRecursive:function(a,b,e){var d;a||(a=this.root);a===this.root&&b&&(d=b(a));!1!==d&&(a.nodes.forEach(function(a){if(a.isInternal){b&&(d=b(a));if(!1===d)return;this.visitNodeRecursive(a,b,e)}else a.body&&b&&b(a.body);e&&e(a)},this),a===this.root&&e&&e(a))},calculateMassAndCenter:function(){this.visitNodeRecursive(null,null,function(a){a.updateMassAndCenter()})}})});
k(e,"Series/Networkgraph/Layouts.js",[e["Core/Chart/Chart.js"],e["Core/Animation/AnimationUtilities.js"],e["Core/Globals.js"],e["Core/Utilities.js"]],function(e,b,a,g){var d=b.setAnimation;b=g.addEvent;var h=g.clamp,v=g.defined,l=g.extend,t=g.isFunction,p=g.pick;a.layouts={"reingold-fruchterman":function(){}};l(a.layouts["reingold-fruchterman"].prototype,{init:function(c){this.options=c;this.nodes=[];this.links=[];this.series=[];this.box={x:0,y:0,width:0,height:0};this.setInitialRendering(!0);this.integration=
a.networkgraphIntegrations[c.integration];this.enableSimulation=c.enableSimulation;this.attractiveForce=p(c.attractiveForce,this.integration.attractiveForceFunction);this.repulsiveForce=p(c.repulsiveForce,this.integration.repulsiveForceFunction);this.approximation=c.approximation},updateSimulation:function(a){this.enableSimulation=p(a,this.options.enableSimulation)},start:function(){var a=this.series,b=this.options;this.currentStep=0;this.forces=a[0]&&a[0].forces||[];this.chart=a[0]&&a[0].chart;this.initialRendering&&
(this.initPositions(),a.forEach(function(a){a.finishedAnimating=!0;a.render()}));this.setK();this.resetSimulation(b);this.enableSimulation&&this.step()},step:function(){var c=this,b=this.series;c.currentStep++;"barnes-hut"===c.approximation&&(c.createQuadTree(),c.quadTree.calculateMassAndCenter());c.forces.forEach(function(a){c[a+"Forces"](c.temperature)});c.applyLimits(c.temperature);c.temperature=c.coolDown(c.startTemperature,c.diffTemperature,c.currentStep);c.prevSystemTemperature=c.systemTemperature;
c.systemTemperature=c.getSystemTemperature();c.enableSimulation&&(b.forEach(function(a){a.chart&&a.render()}),c.maxIterations--&&isFinite(c.temperature)&&!c.isStable()?(c.simulation&&a.win.cancelAnimationFrame(c.simulation),c.simulation=a.win.requestAnimationFrame(function(){c.step()})):c.simulation=!1)},stop:function(){this.simulation&&a.win.cancelAnimationFrame(this.simulation)},setArea:function(a,b,d,e){this.box={left:a,top:b,width:d,height:e}},setK:function(){this.k=this.options.linkLength||this.integration.getK(this)},
addElementsToCollection:function(a,b){a.forEach(function(a){-1===b.indexOf(a)&&b.push(a)})},removeElementFromCollection:function(a,b){a=b.indexOf(a);-1!==a&&b.splice(a,1)},clear:function(){this.nodes.length=0;this.links.length=0;this.series.length=0;this.resetSimulation()},resetSimulation:function(){this.forcedStop=!1;this.systemTemperature=0;this.setMaxIterations();this.setTemperature();this.setDiffTemperature()},restartSimulation:function(){this.simulation?this.resetSimulation():(this.setInitialRendering(!1),
this.enableSimulation?this.start():this.setMaxIterations(1),this.chart&&this.chart.redraw(),this.setInitialRendering(!0))},setMaxIterations:function(a){this.maxIterations=p(a,this.options.maxIterations)},setTemperature:function(){this.temperature=this.startTemperature=Math.sqrt(this.nodes.length)},setDiffTemperature:function(){this.diffTemperature=this.startTemperature/(this.options.maxIterations+1)},setInitialRendering:function(a){this.initialRendering=a},createQuadTree:function(){this.quadTree=
new a.QuadTree(this.box.left,this.box.top,this.box.width,this.box.height);this.quadTree.insertNodes(this.nodes)},initPositions:function(){var a=this.options.initialPositions;t(a)?(a.call(this),this.nodes.forEach(function(a){v(a.prevX)||(a.prevX=a.plotX);v(a.prevY)||(a.prevY=a.plotY);a.dispX=0;a.dispY=0})):"circle"===a?this.setCircularPositions():this.setRandomPositions()},setCircularPositions:function(){function a(b){b.linksFrom.forEach(function(b){w[b.toNode.id]||(w[b.toNode.id]=!0,f.push(b.toNode),
a(b.toNode))})}var b=this.box,d=this.nodes,e=2*Math.PI/(d.length+1),g=d.filter(function(a){return 0===a.linksTo.length}),f=[],w={},m=this.options.initialPositionRadius;g.forEach(function(b){f.push(b);a(b)});f.length?d.forEach(function(a){-1===f.indexOf(a)&&f.push(a)}):f=d;f.forEach(function(a,c){a.plotX=a.prevX=p(a.plotX,b.width/2+m*Math.cos(c*e));a.plotY=a.prevY=p(a.plotY,b.height/2+m*Math.sin(c*e));a.dispX=0;a.dispY=0})},setRandomPositions:function(){function a(a){a=a*a/Math.PI;return a-=Math.floor(a)}
var b=this.box,d=this.nodes,e=d.length+1;d.forEach(function(c,f){c.plotX=c.prevX=p(c.plotX,b.width*a(f));c.plotY=c.prevY=p(c.plotY,b.height*a(e+f));c.dispX=0;c.dispY=0})},force:function(a){this.integration[a].apply(this,Array.prototype.slice.call(arguments,1))},barycenterForces:function(){this.getBarycenter();this.force("barycenter")},getBarycenter:function(){var a=0,b=0,d=0;this.nodes.forEach(function(c){b+=c.plotX*c.mass;d+=c.plotY*c.mass;a+=c.mass});return this.barycenter={x:b,y:d,xFactor:b/a,
yFactor:d/a}},barnesHutApproximation:function(a,b){var c=this.getDistXY(a,b),d=this.vectorLength(c);if(a!==b&&0!==d)if(b.isInternal)if(b.boxSize/d<this.options.theta&&0!==d){var e=this.repulsiveForce(d,this.k);this.force("repulsive",a,e*b.mass,c,d);var f=!1}else f=!0;else e=this.repulsiveForce(d,this.k),this.force("repulsive",a,e*b.mass,c,d);return f},repulsiveForces:function(){var a=this;"barnes-hut"===a.approximation?a.nodes.forEach(function(b){a.quadTree.visitNodeRecursive(null,function(c){return a.barnesHutApproximation(b,
c)})}):a.nodes.forEach(function(b){a.nodes.forEach(function(c){if(b!==c&&!b.fixedPosition){var d=a.getDistXY(b,c);var e=a.vectorLength(d);if(0!==e){var f=a.repulsiveForce(e,a.k);a.force("repulsive",b,f*c.mass,d,e)}}})})},attractiveForces:function(){var a=this,b,d,e;a.links.forEach(function(c){c.fromNode&&c.toNode&&(b=a.getDistXY(c.fromNode,c.toNode),d=a.vectorLength(b),0!==d&&(e=a.attractiveForce(d,a.k),a.force("attractive",c,e,b,d)))})},applyLimits:function(){var a=this;a.nodes.forEach(function(b){b.fixedPosition||
(a.integration.integrate(a,b),a.applyLimitBox(b,a.box),b.dispX=0,b.dispY=0)})},applyLimitBox:function(a,b){var c=a.radius;a.plotX=h(a.plotX,b.left+c,b.width-c);a.plotY=h(a.plotY,b.top+c,b.height-c)},coolDown:function(a,b,d){return a-b*d},isStable:function(){return.00001>Math.abs(this.systemTemperature-this.prevSystemTemperature)||0>=this.temperature},getSystemTemperature:function(){return this.nodes.reduce(function(a,b){return a+b.temperature},0)},vectorLength:function(a){return Math.sqrt(a.x*a.x+
a.y*a.y)},getDistR:function(a,b){a=this.getDistXY(a,b);return this.vectorLength(a)},getDistXY:function(a,b){var c=a.plotX-b.plotX;a=a.plotY-b.plotY;return{x:c,y:a,absX:Math.abs(c),absY:Math.abs(a)}}});b(e,"predraw",function(){this.graphLayoutsLookup&&this.graphLayoutsLookup.forEach(function(a){a.stop()})});b(e,"render",function(){function a(a){a.maxIterations--&&isFinite(a.temperature)&&!a.isStable()&&!a.enableSimulation&&(a.beforeStep&&a.beforeStep(),a.step(),e=!1,b=!0)}var b=!1;if(this.graphLayoutsLookup){d(!1,
this);for(this.graphLayoutsLookup.forEach(function(a){a.start()});!e;){var e=!0;this.graphLayoutsLookup.forEach(a)}b&&this.series.forEach(function(a){a&&a.layout&&a.render()})}});b(e,"beforePrint",function(){this.graphLayoutsLookup&&(this.graphLayoutsLookup.forEach(function(a){a.updateSimulation(!1)}),this.redraw())});b(e,"afterPrint",function(){this.graphLayoutsLookup&&this.graphLayoutsLookup.forEach(function(a){a.updateSimulation()});this.redraw()})});k(e,"Series/Networkgraph/DraggableNodes.js",
[e["Core/Chart/Chart.js"],e["Core/Globals.js"],e["Core/Utilities.js"]],function(e,b,a){var g=a.addEvent;b.dragNodesMixin={onMouseDown:function(a,b){b=this.chart.pointer.normalize(b);a.fixedPosition={chartX:b.chartX,chartY:b.chartY,plotX:a.plotX,plotY:a.plotY};a.inDragMode=!0},onMouseMove:function(a,b){if(a.fixedPosition&&a.inDragMode){var d=this.chart,e=d.pointer.normalize(b);b=a.fixedPosition.chartX-e.chartX;e=a.fixedPosition.chartY-e.chartY;var g=void 0,h=void 0,c=d.graphLayoutsLookup;if(5<Math.abs(b)||
5<Math.abs(e))g=a.fixedPosition.plotX-b,h=a.fixedPosition.plotY-e,d.isInsidePlot(g,h)&&(a.plotX=g,a.plotY=h,a.hasDragged=!0,this.redrawHalo(a),c.forEach(function(a){a.restartSimulation()}))}},onMouseUp:function(a,b){a.fixedPosition&&(a.hasDragged&&(this.layout.enableSimulation?this.layout.start():this.chart.redraw()),a.inDragMode=a.hasDragged=!1,this.options.fixedDraggable||delete a.fixedPosition)},redrawHalo:function(a){a&&this.halo&&this.halo.attr({d:a.haloPath(this.options.states.hover.halo.size)})}};
g(e,"load",function(){var a=this,b,e,l;a.container&&(b=g(a.container,"mousedown",function(b){var d=a.hoverPoint;d&&d.series&&d.series.hasDraggableNodes&&d.series.options.draggable&&(d.series.onMouseDown(d,b),e=g(a.container,"mousemove",function(a){return d&&d.series&&d.series.onMouseMove(d,a)}),l=g(a.container.ownerDocument,"mouseup",function(a){e();l();return d&&d.series&&d.series.onMouseUp(d,a)}))}));g(a,"destroy",function(){b()})})});k(e,"Series/Networkgraph/Networkgraph.js",[e["Core/Globals.js"],
e["Series/NodesComposition.js"],e["Core/Series/Point.js"],e["Core/Series/Series.js"],e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(e,b,a,g,d,h){var k=this&&this.__extends||function(){var a=function(b,f){a=Object.setPrototypeOf||{__proto__:[]}instanceof Array&&function(a,b){a.__proto__=b}||function(a,b){for(var f in b)b.hasOwnProperty(f)&&(a[f]=b[f])};return a(b,f)};return function(b,f){function c(){this.constructor=b}a(b,f);b.prototype=null===f?Object.create(f):(c.prototype=
f.prototype,new c)}}(),l=d.seriesTypes,t=h.addEvent,p=h.css,c=h.defined,q=h.extend,u=h.merge,r=h.pick,n=e.dragNodesMixin;"";h=function(a){function b(){var b=null!==a&&a.apply(this,arguments)||this;b.data=void 0;b.nodes=void 0;b.options=void 0;b.points=void 0;return b}k(b,a);b.defaultOptions=u(g.defaultOptions,{stickyTracking:!1,inactiveOtherPoints:!0,marker:{enabled:!0,states:{inactive:{opacity:.3,animation:{duration:50}}}},states:{inactive:{linkOpacity:.3,animation:{duration:50}}},dataLabels:{formatter:function(){return this.key},
linkFormatter:function(){return this.point.fromNode.name+"<br>"+this.point.toNode.name},linkTextPath:{enabled:!0},textPath:{enabled:!1},style:{transition:"opacity 2000ms"}},link:{color:"rgba(100, 100, 100, 0.5)",width:1},draggable:!0,layoutAlgorithm:{initialPositions:"circle",initialPositionRadius:1,enableSimulation:!1,theta:.5,maxSpeed:10,approximation:"none",type:"reingold-fruchterman",integration:"euler",maxIterations:1E3,gravitationalConstant:.0625,friction:-.981},showInLegend:!1});return b}(g);
q(h.prototype,{forces:["barycenter","repulsive","attractive"],hasDraggableNodes:!0,drawGraph:void 0,isCartesian:!1,requireSorting:!1,directTouch:!0,noSharedTooltip:!0,pointArrayMap:["from","to"],trackerGroups:["group","markerGroup","dataLabelsGroup"],drawTracker:l.column.prototype.drawTracker,animate:void 0,buildKDTree:e.noop,createNode:b.createNode,destroy:function(){this.layout&&this.layout.removeElementFromCollection(this,this.layout.series);b.destroy.call(this)},init:function(){var a=this;g.prototype.init.apply(this,
arguments);t(this,"updatedData",function(){a.layout&&a.layout.stop()});t(this,"afterUpdate",function(){a.nodes.forEach(function(a){a&&a.series&&a.resolveColor()})});return this},generatePoints:function(){var a;b.generatePoints.apply(this,arguments);this.options.nodes&&this.options.nodes.forEach(function(a){this.nodeLookup[a.id]||(this.nodeLookup[a.id]=this.createNode(a.id))},this);for(a=this.nodes.length-1;0<=a;a--){var c=this.nodes[a];c.degree=c.getDegree();c.radius=r(c.marker&&c.marker.radius,this.options.marker&&
this.options.marker.radius,0);this.nodeLookup[c.id]||c.remove()}this.data.forEach(function(a){a.formatPrefix="link"});this.indexateNodes()},getPointsCollection:function(){return this.nodes||[]},indexateNodes:function(){this.nodes.forEach(function(a,b){a.index=b})},markerAttribs:function(a,b){b=g.prototype.markerAttribs.call(this,a,b);c(a.plotY)||(b.y=0);b.x=(a.plotX||0)-(b.width||0)/2;return b},translate:function(){this.processedXData||this.processData();this.generatePoints();this.deferLayout();this.nodes.forEach(function(a){a.isInside=
!0;a.linksFrom.forEach(function(a){a.shapeType="path";a.y=1})})},deferLayout:function(){var a=this.options.layoutAlgorithm,b=this.chart.graphLayoutsStorage,d=this.chart.graphLayoutsLookup,g=this.chart.options.chart;if(this.visible){b||(this.chart.graphLayoutsStorage=b={},this.chart.graphLayoutsLookup=d=[]);var h=b[a.type];h||(a.enableSimulation=c(g.forExport)?!g.forExport:a.enableSimulation,b[a.type]=h=new e.layouts[a.type],h.init(a),d.splice(h.index,0,h));this.layout=h;h.setArea(0,0,this.chart.plotWidth,
this.chart.plotHeight);h.addElementsToCollection([this],h.series);h.addElementsToCollection(this.nodes,h.nodes);h.addElementsToCollection(this.points,h.links)}},render:function(){var a=this.points,b=this.chart.hoverPoint,c=[];this.points=this.nodes;l.line.prototype.render.call(this);this.points=a;a.forEach(function(a){a.fromNode&&a.toNode&&(a.renderLink(),a.redrawLink())});b&&b.series===this&&this.redrawHalo(b);this.chart.hasRendered&&!this.options.dataLabels.allowOverlap&&(this.nodes.concat(this.points).forEach(function(a){a.dataLabel&&
c.push(a.dataLabel)}),this.chart.hideOverlappingLabels(c))},drawDataLabels:function(){var a=this.options.dataLabels.textPath;g.prototype.drawDataLabels.apply(this,arguments);this.points=this.data;this.options.dataLabels.textPath=this.options.dataLabels.linkTextPath;g.prototype.drawDataLabels.apply(this,arguments);this.points=this.nodes;this.options.dataLabels.textPath=a},pointAttribs:function(a,b){var c=b||a&&a.state||"normal";b=g.prototype.pointAttribs.call(this,a,c);c=this.options.states[c];a&&
!a.isNode&&(b=a.getLinkAttributes(),c&&(b={stroke:c.linkColor||b.stroke,dashstyle:c.linkDashStyle||b.dashstyle,opacity:r(c.linkOpacity,b.opacity),"stroke-width":c.linkColor||b["stroke-width"]}));return b},redrawHalo:n.redrawHalo,onMouseDown:n.onMouseDown,onMouseMove:n.onMouseMove,onMouseUp:n.onMouseUp,setState:function(a,b){b?(this.points=this.nodes.concat(this.data),g.prototype.setState.apply(this,arguments),this.points=this.data):g.prototype.setState.apply(this,arguments);this.layout.simulation||
a||this.render()}});n=function(a){function b(){var b=null!==a&&a.apply(this,arguments)||this;b.degree=void 0;b.linksFrom=void 0;b.linksTo=void 0;b.options=void 0;b.radius=void 0;b.series=void 0;b.toNode=void 0;return b}k(b,a);return b}(g.prototype.pointClass);q(n.prototype,{setState:b.setNodeState,init:function(){a.prototype.init.apply(this,arguments);this.series.options.draggable&&!this.series.chart.styledMode&&(t(this,"mouseOver",function(){p(this.series.chart.container,{cursor:"move"})}),t(this,
"mouseOut",function(){p(this.series.chart.container,{cursor:"default"})}));return this},getDegree:function(){var a=this.isNode?this.linksFrom.length+this.linksTo.length:0;return 0===a?1:a},getLinkAttributes:function(){var a=this.series.options.link,b=this.options;return{"stroke-width":r(b.width,a.width),stroke:b.color||a.color,dashstyle:b.dashStyle||a.dashStyle,opacity:r(b.opacity,a.opacity,1)}},renderLink:function(){if(!this.graphic&&(this.graphic=this.series.chart.renderer.path(this.getLinkPath()).addClass(this.getClassName(),
!0).add(this.series.group),!this.series.chart.styledMode)){var a=this.series.pointAttribs(this);this.graphic.attr(a);(this.dataLabels||[]).forEach(function(b){b&&b.attr({opacity:a.opacity})})}},redrawLink:function(){var a=this.getLinkPath();if(this.graphic){this.shapeArgs={d:a};if(!this.series.chart.styledMode){var b=this.series.pointAttribs(this);this.graphic.attr(b);(this.dataLabels||[]).forEach(function(a){a&&a.attr({opacity:b.opacity})})}this.graphic.animate(this.shapeArgs);var c=a[0];a=a[1];
"M"===c[0]&&"L"===a[0]&&(this.plotX=(c[1]+a[1])/2,this.plotY=(c[2]+a[2])/2)}},getMass:function(){var a=this.fromNode.mass,b=this.toNode.mass,c=a+b;return{fromNode:1-a/c,toNode:1-b/c}},getLinkPath:function(){var a=this.fromNode,b=this.toNode;a.plotX>b.plotX&&(a=this.toNode,b=this.fromNode);return[["M",a.plotX||0,a.plotY||0],["L",b.plotX||0,b.plotY||0]]},isValid:function(){return!this.isNode||c(this.id)},remove:function(a,b){var c=this.series,d=c.options.nodes||[],e,f=d.length;if(this.isNode){c.points=
[];[].concat(this.linksFrom).concat(this.linksTo).forEach(function(a){e=a.fromNode.linksFrom.indexOf(a);-1<e&&a.fromNode.linksFrom.splice(e,1);e=a.toNode.linksTo.indexOf(a);-1<e&&a.toNode.linksTo.splice(e,1);g.prototype.removePoint.call(c,c.data.indexOf(a),!1,!1)});c.points=c.data.slice();for(c.nodes.splice(c.nodes.indexOf(this),1);f--;)if(d[f].id===this.options.id){c.options.nodes.splice(f,1);break}this&&this.destroy();c.isDirty=!0;c.isDirtyData=!0;a&&c.chart.redraw(a)}else c.removePoint(c.data.indexOf(this),
a,b)},destroy:function(){this.isNode&&this.linksFrom.concat(this.linksTo).forEach(function(a){a.destroyElements&&a.destroyElements()});this.series.layout.removeElementFromCollection(this,this.series.layout[this.isNode?"nodes":"links"]);return a.prototype.destroy.apply(this,arguments)}});h.prototype.pointClass=n;d.registerSeriesType("networkgraph",h);"";return h});k(e,"masters/modules/networkgraph.src.js",[],function(){})});
//# sourceMappingURL=networkgraph.js.map