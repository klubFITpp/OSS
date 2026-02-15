## Jak na laborky PSI
- primarne opakovani proseminaru

### Osnova
1. Proc resime site / sitove vrstvy
2. IP adresa, default gateway
3. Lokalni sit / MAC adresy
4. **Example** - lokalni sit. Nastaveni ip + ping (ARP)
5. Co je to ARP
6. Co je to DHCP
7. **Exaple** - vice pocitacu, automaticka konfigurace

### Proc resime site / sitove vrstvy
- mame spoustu vyrobcu, kazdy nemuze mit vlastni protokol
- ruzne aplikace / uzivatele mohou mit ruzne potreby
  - reliability
  - speed (games/video)
  - order
  - encryption
  - i treba fyzicky prenos - pocet kabelu, elektrina/optika/vlny - wifi atd.
- "vrstvy" jsou prirozeny zpusob jak to delat
  - protocol, info...., data(another layer)
  - kazda vrstva "resi problem te predchozi"

- ISO/OSI
  - referencni model (nepouziva, je na nem popsano jak co ma/muze fungovat)
  - fyzicka vrstva (kabel)
  - data-linkova vrstva ("mezi sousedy")
  - sitova vrstva (dostat se do spravne zeme,mesta,domu)
  - transportni vrstva (navazani spojeni, kontrola ze vse dorazilo)
  - aplikacni (vse ostatni - sifrovani, aplikacni data, relace)

### Sitova vrstva / default gateway
- prenos informaci na spravne misto ("Ceska Posta na pobocku")
- IP adresa = identifikator ("PSC")
- routovaci tabulka - data posilame jen tam, kam se maji dostat
- prace s rozsahy
- default gateway = nevim, neznam = "posilam test kamaradovi"
- IP 32 bitu, typicky psane jako 8 bitove segmenty rozdelene teckou
- nejcasteji se budeme bavit o IP rozsahu - podle tech jsou definovane routovaci tabulky
  - 0.0.0.0/0 = defalut gateway (rozsah obsahujici vsechny IP adresy)
  - specictejsi definice rozsahu ma prioritu **1.2.3.4/32** over **1.2.3.0/24**
- IP adresa, kterou pouzivate nemusi byt pristupna z otevreneho internetu
  - 10.0.0.0/8
  - 192.168.0.0/16
  - 172.16.0.0/20

### Data Linkova vrstva
- doruceni do domu po danem meste
- MAC adresa ("oznaceni postovni schranky") - co kdyz mame 2 schranky?
- doplnuje sitovou vrstvu
  - pripojime se a nemame IP adresu
  - mame spatnou adresu (muzeme hledat IP adresy ostatnich zarizeni)
  - hledani utocnika schovaneho v siti

> Ukazka #1 (GNS3, nastaveni IP)

### ARP
- Hledani mac adresy podle IP adresy
  - "JSEM 1.1.1.1 MA TU NEKDO ADRESU 1.2.3.4?"
  - "Ahoj 1.1.1.1, ja mam 1.2.3.4"
- aby dotazu nebylo moc, docasne ulozime

### DHCP
- automaticky nastavuje sit novym zarizenim
- "DHCP pool" - IP adresy, ktere jeste nikdo na siti nepouziva
- 4 zpravy
  - Discover (je tu nekdo kdo mi rekne jak se pripojit)
  - Offer (muzu ti pujcit tuhle IP adresu, default gateway je ..., DNS je ...)
  - Request (muzu tu IP adresu pouzivat?)
  - Acknowledgement (jasne, vsechno vpohode)

> Ukazka #2 (GNS3, spusteni DHCP serveru, nastaveni IP, analyza DHCP)
> start_predefined_dhcp_server
> 192.168.1.1/24
