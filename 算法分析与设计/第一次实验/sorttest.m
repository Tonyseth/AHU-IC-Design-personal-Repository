%写一个插入排序
clc,clear
A =input('请输入一个数组：');
n = length(A);
for j=2:n
    x=A(j);
    i=j-1;
    while i>0 && x<A(i)
        A(i+1)=A(i);
        i=i-1;
        A(i+1)=x;
    end
end 


% function [sorted] = insort(arr)
%     sorted = arr;
% 
%     for i = 2:length(sorted)
%         key = sorted(i);
%         j = i - 1;
% 
%         while j > 0 && sorted(j) > key
%             sorted(j + 1) = sorted(j);
%             j = j - 1;
%         end
% 
%         sorted(j + 1) = key;
%     end
% 
% end
