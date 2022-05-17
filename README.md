# vector

## Fukcijų pavyzdžiai

*  **vector::data**  
  Testavimo kodas:
    ```c++
        std::vector<int> v (5);

        int* p = v.data();

        *p = 10;
        ++p;
        *p = 20;
        p[2] = 100;

        std::cout << "v contains:";
        for (unsigned i=0; i<v.size(); ++i)
        std::cout << ' ' << v[i];
        std::cout << '\n';


        vector<int> v1 (5);

        int* p1 = v1.data();

        *p1 = 10;
        ++p1;
        *p1 = 20;
        p1[2] = 100;

        std::cout << "v1 contains:";
        for (unsigned i=0; i<v1.size(); ++i)
        std::cout << ' ' << v1[i];
        std::cout << '\n';
    ```
    Rezultatas:  
    ```console
        v contains: 10 20 0 100 0
        v1 contains: 10 20 0 100 0
    ```

*  **vector::emplace**  
  Testavimo kodas:
    ```c++
        std::vector<int> v = {10,20,30};

        auto it = v.emplace ( v.begin()+1, 100 );
        v.emplace ( it, 200 );
        v.emplace ( v.end(), 300 );

        std::cout << "v contains:";
        for (auto& x: v)
            std::cout << ' ' << x;
        std::cout << '\n';


        vector<int> v1 = {10,20,30};

        auto it1 = v1.emplace ( v1.begin()+1, 100 );
        v1.emplace ( it1, 200 );
        v1.emplace ( v1.end(), 300 );

        std::cout << "v1 contains:";
        for (auto& x: v1)
            std::cout << ' ' << x;
        std::cout << '\n';
    ```
    Rezultatas:  
    ```console
        v contains: 10 200 100 20 30 300
        v1 contains: 10 200 100 20 30 300
    ```

*  **vector::erase**  
  Testavimo kodas:
    ```c++
        std::vector<int> v;

        for (int i=1; i<=10; i++) v.push_back(i);

        v.erase (v.begin()+5);

        v.erase (v.begin(),v.begin()+3);

        std::cout << "v contains:";
        for (unsigned i=0; i<v.size(); ++i)
            std::cout << ' ' << v[i];
        std::cout << '\n';


        vector<int> v1;

        for (int i=1; i<=10; i++) v1.push_back(i);

        v1.erase (v1.begin()+5);

        v1.erase (v1.begin(),v1.begin()+3);

        std::cout << "v1 contains:";
        for (unsigned i=0; i<v1.size(); ++i)
            std::cout << ' ' << v1[i];
        std::cout << '\n';
    ```
    Rezultatas:  
    ```console
        v contains: 4 5 7 8 9 10
        v1 contains: 4 5 7 8 9 10
    ```

*  **vector::resize**  
  Testavimo kodas:
    ```c++
        std::vector<int> v;

        for (int i=1;i<10;i++) v.push_back(i);

        v.resize(5);
        v.resize(8,100);
        v.resize(12);

        std::cout << "v contains:";
        for (int i=0;i<v.size();i++)
            std::cout << ' ' << v[i];
        std::cout << '\n';


        vector<int> v1;

        for (int i=1;i<10;i++) v1.push_back(i);

        v1.resize(5);
        v1.resize(8,100);
        v1.resize(12);

        std::cout << "v1 contains:";
        for (int i=0;i<v1.size();i++)
            std::cout << ' ' << v1[i];
        std::cout << '\n';
    ```
    Rezultatas:  
    ```console
        v contains: 1 2 3 4 5 100 100 100 0 0 0 0
        v1 contains: 1 2 3 4 5 100 100 100 0 0 0 0
    ```

*  **vector::shrink_to_fit**  
  Testavimo kodas:
    ```c++
        std::vector<int> v (100);
        std::cout << "1. capacity of v: " << v.capacity() << '\n';

        v.resize(10);
        std::cout << "2. capacity of v: " << v.capacity() << '\n';

        v.shrink_to_fit();
        std::cout << "3. capacity of v: " << v.capacity() << '\n';


        std::vector<int> v1 (100);
        std::cout << "1. capacity of v1: " << v1.capacity() << '\n';

        v1.resize(10);
        std::cout << "2. capacity of v1: " << v1.capacity() << '\n';

        v1.shrink_to_fit();
        std::cout << "3. capacity of v1: " << v1.capacity() << '\n';
    ```
    Rezultatas:  
    ```console
        1. capacity of v: 100
        2. capacity of v: 100
        3. capacity of v: 10
        1. capacity of v1: 100
        2. capacity of v1: 100
        3. capacity of v1: 10
    ```

*  **vector::swap**  
  Testavimo kodas:
    ```c++
        std::vector<int> foo (3,100);
        std::vector<int> bar (5,200);

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
        

        vector<int> foo1 (3,100);
        vector<int> bar1 (5,200);

        foo1.swap(bar1);

        std::cout << "foo1 contains:";
        for (unsigned i=0; i<foo1.size(); i++)
            std::cout << ' ' << foo1[i];
        std::cout << '\n';

        std::cout << "bar1 contains:";
        for (unsigned i=0; i<bar1.size(); i++)
            std::cout << ' ' << bar1[i];
        std::cout << '\n';
    ```
    Rezultatas:  
    ```console
        foo contains: 200 200 200 200 200
        bar contains: 100 100 100
        foo1 contains: 200 200 200 200 200
        bar1 contains: 100 100 100
    ```  
---

## Vektoriaus užpildymo naudojant *vector::push_back()* spartos palyginmas
Testavimo kodas:
```c++
#include <chrono>
using hrClock = std::chrono::high_resolution_clock;
```
```c++
    auto v1_start = hrClock::now();
    unsigned int sz = 10000;  // 100000, 1000000, 10000000, 100000000
    
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
    auto v1_stop = hrClock::now();
    auto v1_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(v1_stop - v1_start);
    std::cout << v1_duration.count() * 1e-9 << "s\n";

    auto v2_start = hrClock::now();
    vector<int> v2;
    for (int i = 1; i <= sz; ++i)
        v2.push_back(i);
    auto v2_stop = hrClock::now();
    auto v2_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(v2_stop - v2_start);
    std::cout << v2_duration.count() * 1e-9 << "s\n";
```
<br>  

### Rezultatai
|  | 10,000 | 100,000 | 1,000,000 | 10,000,000 | 100,000,000 |
|---|---|---|---|---|---|
| std::vector | 0s | 0.0020387s | 0.0129931s | 0.146999s | 1.36703s |
| vector | 0s | 0.0020377s | 0.0160105s | 0.183046s | 1.60603s |
---

### Atminties perskirstymas
Tetavimo kodas:
```c++
    unsigned int sz = 100000000;
    int p1 = 0, p2 = 0;

    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i) {
        v1.push_back(i);
        if (v1.size() == v1.capacity())
        p1++;
    }

    vector<int> v2;
    for (int i = 1; i <= sz; ++i) {
        v2.push_back(i);
        if (v2.size() == v2.capacity())
        p2++;
    }
```
Rezultatas:
```console
    p1: 27
    p2: 27
```
---
## Spartos analizė

### std::vector
| Įrašų kiekis | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0.0030017 | 0 | 0 | 0.0059955 | 0.0180172 |
| 10,000 | 0.0199938 | 0.0039748 | 0.0029974 | 0.0180094 | 0.0642923 |
| 100,000 | 0.184032 | 0.0440006 | 0.0300147 | 0.128 | 0.489988 |
| 1,000,000 | 1.82604 | 0.529997 | 0.26796 | 1.197 | 4.76364 |
| 10,000,000 | 17.886 | 6.54105 | 2.67504 | 11.752 | 48.2796 |

### vector
| Įrašų kiekis | Duomenų paruošimas naudojimui programoje, s | Studentų rūšiavimas pagal vardus, s | Studentų rūšiavimas į dvi kategorijas, s | Studentų išvedimas į du naujus failus, s | Programos veikimo laikas, s |
|---|---|---|---|---|---|
| 1,000 | 0.0030024 | 0.0009995 | 0.0019811 | 0.0030035 | 0.0160106 |
| 10,000 | 0.0260451 | 0.0110303 | 0.0200013 | 0.015854 | 0.099345 |
| 100,000 | 0.239034 | 0.0970005 | 0.376034 | 0.143997 | 0.973035 |
| 1,000,000 | 2.307 | 0.993034 | 3.82303 | 1.163 | 9.31 |
| 10,000,000 | 24.376 | 9.979 | 38.3776 | 12.4497 | 95.6563 |

*\* Programos testvaimas buvo atliktas naudojant g++ kompiliatorių (gcc version 8.1.0, x86_64-posix-seh-rev0)*  
*\* Naudota sistema: i5-8300h, 16gb 2667 MHz CL19, Samsung 970 EVO Plus*  
*\* Programos veikimo laikas buvo pradėtas skaičiuoti sugeneravus duomenų failą*  
*\* Testuojant buvo naudojami failai su 10 namų darbų pažymių*  
*\* Testuojant studentai buvo skirtomi panaudojant vieną naują konteinerį*  

![1,000,000](https://user-images.githubusercontent.com/80033246/168855066-05776d23-0b80-4746-9cb4-159983b95fa2.png)  

![10,000,000](https://user-images.githubusercontent.com/80033246/168855168-eb3c1d5d-c1fa-49dd-a84e-4b51f815a952.png)