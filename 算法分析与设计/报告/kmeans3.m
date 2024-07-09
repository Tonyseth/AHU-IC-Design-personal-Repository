function [idx, mu] = k_means3(X,k)
% X: data set;
% k:the number of classfication
% mu:clustering center
% idx:label
if nargin<1
% data set;
Sigma = [1, 0; 0, 1];
mu1 = [1, -1];
x1 = mvnrnd(mu1, Sigma, 200);
mu2 = [5, -4];
x2 = mvnrnd(mu2, Sigma, 200);
mu3 = [1, 4];
x3 = mvnrnd(mu3, Sigma, 200);
mu4 = [6, 4];
x4 = mvnrnd(mu4, Sigma, 200);
mu5 = [7, 0.0];
x5 = mvnrnd(mu5, Sigma, 200);
% Show the data points 
plot(x1(:,1), x1(:,2), 'r.'); hold on;
plot(x2(:,1), x2(:,2), 'b.');
plot(x3(:,1), x3(:,2), 'k.');
plot(x4(:,1), x4(:,2), 'g.');
plot(x5(:,1), x5(:,2), 'm.');
X = [x1; x2; x3; x4; x5];
k = 5;
end
[n,~] = size(X);
% select initial clustering center
m = 30;
index_set = zeros(m, k);
r = zeros(m, 1);
for i=1:m
    index_set(i, :) = randperm(n, k);
    X_init = X(index_set(i,:),:);
    for j = 1 : n
        R = repmat(X(j, :), k, 1) - X_init;
        r(i) = r(i) + sum(sum(R.*R));
    end
end
p = find(r==min(r));
final_index = index_set(p,:);

X_init = X(final_index, :);
label = zeros(n, 1);
mu = X_init;
mu_new = mu;
eps = 1e-6;
delta = 1;
while (delta > eps)
    mu = mu_new;
    for i =1:n
        y = repmat (X(i, :), k, 1);
        dist = y - mu;
        d = sum(dist.*dist,2);
        j = find(d==min(d));
        label(i) = j;
    end
    for j = 1 : k
        order = find(label == j);
        mu_new(j, :) = mean(X(order, :), 1);
    end
    delta = sqrt(sum(sum((mu-mu_new).*(mu-mu_new))));
end
label = zeros(n, 1);
for i = 1 : n
    R = repmat(X(i,:),k,1) - mu;
    Residual = sum(R.*R,2);
    j = find(Residual == min(Residual));
    label(i) = j;
end
idx = label;
end