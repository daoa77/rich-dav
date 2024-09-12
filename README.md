# rich-dav
**Alexander Sebastian Richard (5223600074)**
**Dava Rizqiika Indra Putrawan (5223600090)**
1). Menampilkan Status Pesanan di Meja (Display Order Status) : Fitur ini memungkinkan pengguna untuk menampilkan status pesanan di semua meja beserta emosi dari masing-masing pelanggan yang duduk di meja tersebut seperti apakah pesanan belum diambil pelayanan (Order Not Yet Taken), atau Order sedang di proses (Order In Kitchen), dan Order sudah di sajikan ke pelanggan (Order Served)    
2). Pengambilan Pesanan oleh Pelayan (Take Order) : Pengguna dapat memilih meja tertentu untuk mengambil pesanan pelanggan,Pengguna dapat memilih meja tertentu untuk mengambil pesanan pelanggan, 
3). Simulasi Proses Pesanan (Simulate Order Processing) : Memberikan jeda satu detik menggunakan fungsi std::this_thread::sleep_for(), Mengurangi tingkat emosi pelanggan setiap detik selama mereka menunggu. Pelanggan yang menunggu lama akan menjadi kurang bahagia.
4). Emosi Pelanggan (Customer Emotion) : Pelanggan di setiap meja memiliki tingkat emosi yang dimulai dari 5 (bahagia) dan berkurang seiring waktu jika mereka harus menunggu terlalu lama, Setiap kali simulasi diproses, tingkat emosi pelanggan yang belum menerima pesanan akan berkurang. Namun, setelah pesanan diantar, emosi pelanggan kembali ke angka 5.
