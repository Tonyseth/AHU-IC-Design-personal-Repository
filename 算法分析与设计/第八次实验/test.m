% 创建一个带权重的图
edgeList = [1 2; 2 3; 2 4; 3 4; 3 1; 5 7];
weights = [1 1 2 5 8 2];
g = graph(edgeList(:, 1), edgeList(:, 2), weights);

% 使用函数
spanningtree = Kruskal(g);
function [spanningTree usedEdges varargout] = Kruskal(g, varargin)
    % KRUSKAL is a function for searching spanning tree.
    %
    %Synopsis
    %         SPANNINGTREE = KRUSKAL(G,USERPARAMPOSITION)
    % [SPANNINGTREE USEDEDGES] = KRUSKAL(G,USERPARAMPOSITION)
    %Description
    % Input is an object of type graph G, which is has to be weighted.
    % Output of the function is an graph object respresenting
    % the spanning Tree of graph G. If a graph G was not weighted,
    % you would have to add weightes of edges. It's necessary to enter a number
    % of parameter like a second input parameter. In others instances
    % will be taken a first value of edgeDatatype
    % parameter of input graph g has to be 'double'.
    % Variable USEDEDGES includes order of edges as was added to the spaning
    % tree and there is order of usage in the second row.
    %
    %Example
    % adding weightes of edges:
    % >> edgeList = {1 2 1; 2 3 1; 2 4 2; 3 4 5; 3 1 8; 5 7 2};
    % >> g = graph('edl',edgeList,'edgeDatatype',{'double'});
    % >> spanningtree = kruskal(g)
    %
    % See also GRAPH/GRAPH, GRAPHEDIT, GRAPH/BORUVKA, GRAPH/PRIM, SPANNINGTREE_DEMO

    % check of the input parameters
    if nargin > 1

        if isnumerical(varargin{1})
            userParamPos = varargin{1};
            userParamPos = round(userParamPos(1));
        else
            error ('TORSCHE:graph:wrongparamtype', ...
            'Second parameter must be numerical!');
        end

    else
        userParamPos = 1;
    end

    % load of edges
    edgelist = get(g, 'edl');

    if size(edgelist, 2) < (userParamPos + 2) || ...
            ~all(cellfun(@length, {edgelist{:, (userParamPos + 2)}}, 'UniformOutput', true) == 1)
        error ('TORSCHE:graph:weightsOfGraphAreMissing', 'Weights of edges are missing!');
    end

    edgesTemp = get(g, 'edl');
    dataType = get(g, 'edgeDatatype');

    if size(dataType, 1) == 0 || strcmp(dataType(1), 'double') == 0

        if isa(edgesTemp{1, (userParamPos + 2)}, 'double')
            set(g, 'edl', edgesTemp, 'edgeDatatype', {'double'});
            warning('TORSCHE:graph:weightsOfGraphAreMissing', 'Edge data type missing, set to "double"');
        else
            error ('TORSCHE:graph:weightsOfGraphAreMissing', 'Weights of edges are missing!');
        end

    end

    % load of nodes and parameter VertexFinish, which is represent connected space
    E = cell2mat(edgesTemp(:, [1:2 userParamPos + 2]))';
    costE = E(3, :);
    vertexTemp = get(g, 'ndl');
    VertexFinish = cell2mat(vertexTemp(:, 1));

    if min(VertexFinish) < 1
        error ('TORSCHE:graph:wrongEnteredNodeOfGraph', 'Node of graph were wrong entered!');
    end

    % edge index for removing (default all edges will be erase)
    eAddIndex = zeros(1, size(costE, 2));
    %% ALGORITHM
    % Kruskal's algorithm
    % Input: A connected undirected graph $G$, weigths $c: E(G)\rightarrow \mathbb{R}$
    % Output: A spanning tree $T$ of minimum weight
    % Ref: lit-Korte
    %% 1 Sort the edges such that $c(e_1) \leq c(e_2)\leq \ldots \leq c(e_m)$
    [tempE eOrder] = sort(costE, 2, 'ascend');
    %% 2 Set $T:=(V(G),0)$.
    j = 1;
    %% 3 For $i:1$ to $m$ do: ...
    while min(VertexFinish) ~= max(VertexFinish) && j <= size(E, 2) % First conndition check if all nodes are connected, second if there are any unused edges.
        %% ... if $T + e_i$ contains no circuit ...
        if VertexFinish(E(1, eOrder(j))) ~= VertexFinish(E(2, eOrder(j)))
            %% ... then set $T:= T + e_i$.
            eAddIndex(eOrder(j)) = max(eAddIndex) + 1;
            VertexFinish(find(VertexFinish == VertexFinish(E(2, eOrder(j))))) = VertexFinish(E(1, eOrder(j)));
        end

        %%
        j = j + 1;
    end

    %% END ALGORITHM
    eAddedIndex = find(eAddIndex);
    [tmp, eAddedOrder] = sort(eAddIndex(eAddedIndex));
    usedEdges = eAddedIndex(eAddedOrder);
    usedEdges = [usedEdges; 1:length(usedEdges)];
    varargout{1} = removeedge(g, find(eAddIndex ~= 0));
    % modification of g to panninTree graph
    spanningTree = removeedge(g, find(eAddIndex == 0));
end
