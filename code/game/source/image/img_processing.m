% 去除图片的白边（png四周透明部分）

imgDir = dir('*.png');

for i = 1 : length(imgDir)
    origin = imread(imgDir(i).name);
    bw = rgb2gray(origin);
    min_x = min(find(sum(bw, 1) > 15)); % 找到需要裁剪的最左边的位置
    max_x = max(find(sum(bw, 1) > 15)); % 找到需要裁剪的最右边的位置
    min_y = min(find(sum(bw, 2) > 15)); % 找到需要裁剪的最上边的位置
    max_y = max(find(sum(bw, 2) > 15)); % 找到需要裁剪的最下边的位置
    img = imresize(origin(min_y:max_y, min_x:max_x, :), 0.8);
    alpha = ones(size(img, 1), size(img, 2));
    alpha(rgb2gray(img) < 40) = 0;
    imwrite(img, imgDir(i).name, 'Alpha', alpha);
end