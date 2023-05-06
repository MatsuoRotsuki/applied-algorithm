// Bước 1: Đọc file dữ liệu đầu vào của đồ thị G đã cho (file có cấu trúc) Đối với file dữ liệu đầu vào aij = 0 khi không 
// có đường đi từ i->j, thủ tục đọc file sẽ chuyển các giá trị 0 này thành 99999 (vô cực dương).
// Bước 2: Gọi thủ tục tìm đường đi ngắn nhất giữa mọi cặp đỉnh trong đồ thị bằng thuật toán Floyd-Warshall. 
// Bước 3: Gọi thủ tục tìm cây khung nhỏ nhất cho từng đồ thị con của G’ tìm được ở bước 2, G’=(V,E,w’) (đồ thị con <W∪S> 
// sinh bởi W∪S trong G’ với S ⊂ V-W, card(S) ≤ m-2). Trong các cây phủ đó tìm cây T’ có tổng trọng số nhỏ nhất. 
// Bước 4: Xây dựng cây Steiner cho cây phủ T’ tìm được ở bước 3.
// Bước 5: Kết xuất giá trị sang file lưu trữ. 
// Bước 6: Kết thúc.