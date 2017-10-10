#encoding "utf-8"

Who -> Noun<kwtype="персона">;      // используем слова из статьи "персона"
Consuming -> Verb; // любой глагол
Drink -> Noun<kwtype="алкоголь">;                // используем слова из статьи "алкоголь"

Drinking -> Who interp (Drinking.Who)
        Consuming interp (Drinking.Consuming)
        Drink interp (Drinking.Drink);

