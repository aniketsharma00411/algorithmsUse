/* Graphs: Breadth-first search */
//this function will output a object of key value pair where key is the node and value is the distance from the root node.
function bfs(graph, root) {
    var nodesLen = {};//this object is used to store the distances to the root node
    
    for (var i = 0; i < graph.length; i++) {
      nodesLen[i] = Infinity;
    }
    //set all distances at infinity,incase if a node is not reachable from root node
    nodesLen[root] = 0; //distances from root node to root node is zero
    
    var queue = [root]; //queue to keep in track of nodes to visit
    var current; //current node we are traversing
  
    while (queue.length != 0)//keep traversing the nodes until no more node in the queue is left to traverse 
     {
      current = queue.shift();//poping of the node from queue to traverse
      
      var curConnected = graph[current];//store all the nodes connected to the current node,at beginning is root node
      var neighborIdx = []; //to store the list of nodes connected to current node
      var idx = curConnected.indexOf(1); // find the first node connected to the current node from curconnected array and store it in idx. 1 means connected.If there is no connection indexOf return -1
      while (idx != -1)// if indexOf doesn't return -1
        {
            neighborIdx.push(idx);
            idx = curConnected.indexOf(1, idx + 1); //look for the next connected node
        }
      
      for (var j = 0; j < neighborIdx.length; j++) {
        if (nodesLen[neighborIdx[j]] == Infinity) //initially its infinity
        {
          nodesLen[neighborIdx[j]] = nodesLen[current] + 1;//set the distance
          queue.push(neighborIdx[j]); //push the neighbouring nodes to the queue to visit them next 
        }
      }
    }
    return nodesLen;
  };
  
  var exBFSGraph = [
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0]
  ];
  
  console.log(bfs(exBFSGraph, 1));//sending 1 as root node to bfs function. Trying to find how far every node is from the node 1