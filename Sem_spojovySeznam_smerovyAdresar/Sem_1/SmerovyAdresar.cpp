#include "SmerovyAdresar.h"

SmerovyAdresar::SmerovyAdresar()
{
	mesta = SpojovySeznam();
}

SmerovyAdresar::~SmerovyAdresar()
{
}

void SmerovyAdresar::vloz(std::string mesto, std::string psc, std::string ulice)
{
	Prvek* m = mesta.najdiNeboVloz(mesto);
	if (m == nullptr) {
		m = mesta.najdi(mesto);
		Prvek* p = new Prvek(psc);
		Prvek* u = new Prvek(ulice);
		SpojovySeznam* sPsc = new SpojovySeznam(p);
		SpojovySeznam* sUl = new SpojovySeznam(u);
		m->setSeznam(sPsc);
		p->setSeznam(sUl);
	}
	else {
		Prvek* p = m->getSeznam()->najdiNeboVloz(psc);
		if (p == nullptr) {
			m->getSeznam()->najdiNeboVloz(psc)->setSeznam(new SpojovySeznam(new Prvek(ulice)));
		}
		else {
			p->getSeznam()->najdiNeboVloz(ulice);
		}
	}
	

}

bool SmerovyAdresar::najdiRozsahPsc(std::string mesto, std::string& pscmin, std::string& pscmax)
{
	Prvek* m = mesta.najdi(mesto);
	if (m == nullptr) {
		return false;
	}
	else {
		Prvek* max = m->getSeznam()->najdiExtrem(Maximum);
		if (max == nullptr) return false;
		else {
			pscmax = max->getKlic();
			pscmin = m->getSeznam()->najdiExtrem(Minimum)->getKlic();
			return true;
		}
	}
}

void SmerovyAdresar::vypis()
{
	mesta.vypis();
}
