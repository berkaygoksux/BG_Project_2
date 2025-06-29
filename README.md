# Sınıfta Eşya Arama

**Açıklama:**  
Bu proje, bir sınıfta kaybolan eşyaların bulunması için geliştirilmiş interaktif 3D bir uygulamadır. Kullanıcı, sınıftaki masa, çekmece ve kutu gibi nesneleri seçip işaretleyerek kaybolan eşyasını aramayı yönlendirebilir.  
OpenGL, GLFW ve GLM kütüphaneleri kullanılarak geliştirilmiştir.

---

## Özellikler

- 3D sahne oluşturma (masa, çekmece, kutu)
- FPS tarzı kamera hareketi
- Nesne seçimi ve işaretleme
- Nesne döndürme ve hareket ettirme
- Basit renk ve doku kullanımı

---

## Kurulum ve Çalıştırma

1. Gereksinimler:  
   - C++17 destekleyen derleyici  
   - CMake (>=3.10)  
   - GLFW  
   - OpenGL destekli grafik kartı  
   - GLAD, GLM ve STB Image kütüphaneleri

2. Proje klonlama ve derleme:
    ```bash
    git clone https://github.com/berkaygoksux/BG_Project_2.git
    cd BG_Project_2
    mkdir build && cd build
    cmake ..
    make
    ./sinifta_esya_arama
    ```

3. Doku dosyası `textures/wood.jpg` dizininde bulunmalı.

---

## Dosya Yapısı

- `src/` : Kaynak kod dosyaları (`main.cpp`, `scene.cpp`, `shader_utils.h` vb.)
- `shaders/` : GLSL vertex ve fragment shader dosyaları
- `textures/` : Doku resimleri
- `libs/` : Harici kütüphaneler (GLAD, STB Image)

---

## Kullanım

- WASD ve fare ile sahnede dolaşabilirsiniz.
- Nesne seçmek için sol fare tıklaması kullanılır.
- Seçilen nesne hareket ettirilebilir ve döndürülebilir.
- Program, seçilen nesnenin bilgisini terminale yazar.
