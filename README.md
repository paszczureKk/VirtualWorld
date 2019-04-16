# VirtualWorld

Zaczynając, świat posiada generowaną planszę jako osobny obiekt. Podobne rozwiązanie zostało zastosowane do układu interfejsu użytkownika.
Przy uruchomieniu gry, metoda Populate(int) [->World<-] tworzy po dwa osobniki każdego gatunku. W celach prezentacyjnych, polecam modyfikować
właśnie tę metodę. Wyjątkiem jest gracz, zakładamy 1 instancję gracza w świecie gry.

Granice planszy są twarde, nie przewiduje się przejść cyklicznych po mapie.

Zachowania organizmów zaimplementowano zgodnie ze stratnym modelem rozgrywki, co oznacza stratę ruchu w przypadku ruchu nieprawidłowego lub
ruchu zachowawczego (np. lis przy aktywowanej umiejętności specjalnej NIE IDZIE w stronę osobnika silniejszego, lecz nie podejmuje również
żadnego innego ruchu)

Nowonarodzone stworzenia nie podejmują ruchu (co wynikałoby z ich umiejscowieniu na liście), lecz zostają umieszczone w świecie gry, co umożliwia
interakcję z nimi nawet tuż po narodzinach. Efekt ten osiągnięto za pomocą dwóch buforów - organizmów urodzonych i martwych.
