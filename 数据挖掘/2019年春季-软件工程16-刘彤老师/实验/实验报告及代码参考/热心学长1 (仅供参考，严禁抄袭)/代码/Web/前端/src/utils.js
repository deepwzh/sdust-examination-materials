import G6 from '@antv/g6';
import Hierarchy from '@antv/hierarchy';

export default function get_tree_graph(mount_node, data, edges) {
  // const res = response.tree_data;
  // console.log(res);
  // const data = res.nodes;
  // console.log(data);
  // const edges = res.edges;
  var graph = new G6.TreeGraph({
    container: mount_node,
    width: window.innerWidth,
    height: window.innerHeight,
    pixelRatio: 2,
    modes: {
      default: [{
        type: 'collapse-expand',
        onChange: function onChange(item, collapsed) {
          var data = item.get('model').data;
          data.collapsed = collapsed;
          return true;
        }
      }, 'drag-canvas', 'zoom-canvas']
    },
    defaultNode: {
      size: [100,50],
      shape: 'rect',
      anchorPoints: [[0.5, 0.5]]
    },
    defaultEdge: {
      shape: 'cubic-horizontal'
    },
    nodeStyle: {
      default: {
        fill: '#40a9ff',
        stroke: '#096dd9',
        radius: 20
      }
    },
    edgeStyle: {
      default: {
        stroke: '#A3B1BF',
  
      }
    },
    layout: function layout(data) {
      return Hierarchy.dendrogram(data, {
        direction: 'LR', // H / V / LR / RL / TB / BT
        nodeSep: 70,
        rankSep: 200
      });
    }
  });
  graph.data(data);
  graph.render();
  graph.getNodes().forEach(function(node) {
    //console.log(node);
    var model = node.get('model');
    model.label = model.data.value;
    model.labelCfg = {
      offset: -50,
      style: {
        textAlign: 'center',
        fill: '#666'
      }
    };
    if (model.children && model.children.length > 0) {
      model.labelCfg.position = 'left';
    } else {
      model.labelCfg.position = 'left';
    }
  });
  graph.getEdges().forEach(function(edge) {
    var model = edge.get('model');
    //console.log(model);
    for (let i = 0; i < edges.length; i++) {
      //console.log(edges[i].id, model.id);	
      if (edges[i].id === model.id) {
        model.label = edges[i].value;  
        console.log(model.id);
          break;
        }
    }
    
  });
  graph.refresh();
  graph.fitView();

}