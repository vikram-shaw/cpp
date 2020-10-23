#include<bits/stdc++.h>
using namespace std;

class picture
{
	public:
	string city,place,ext;
	bool operator<(picture& p)
	{
		if(city == p.city)
			return place < p.place;
		return city < p.city;
	}
	
	bool operator==(picture& p)
	{
		return p.city == city && p.place == place && p.ext == ext;
	}
};

vector<string> getCity(vector<string>& names)
{
	vector<string> city;
	for(string c: names)
	{
		for(int i=0;i<(int)c.length();i++)
		{
			string tem = "";
			if(c[i] == '-')
			{
				//city.push_back(names.substr(0,i));
				for(int j=0;j<i;j++)
					tem += c[j];
				city.push_back(tem);
				break;
			}
		}
	}
	return city;
}

vector<string> getExt(vector<string>& names)
{
	vector<string> ext;
	for(string c: names)
	{
		for(int i=0;i<(int)c.length();i++)
		{
			if(c[i] == '.')
			{
				string tem = "";
				for(int j=i+1;j<(int)c.length();j++)
					tem += c[j];
				ext.push_back(tem);
				break;
			}
		}
	}
	return ext;
}

vector<string> getPlace(vector<string>& names)
{
	vector<string> place;
	for(string p: names)
	{
		int i=0;
		while(p[i] != '-')
			i++;
		int s = i + 1;
		for(;i<(int)p.length();i++)
		{
			if(p[i] == '.')
			{
				string tem = "";
				for(int j=s;j<i;j++)
					tem += p[j];
				place.push_back(tem);
				break;
			}
		}
	}
	return place;
}

int main()
{
	vector<string> names = {"kolkata-maidan.jpeg","delhi-qutub.png","hyderabad-charminar.jpeg","delhi-redfort.jpg","kolkata-museum.png","kolkata-botanicalgarden.jpeg"};
	vector<string> city, place, ext;
	city = getCity(names);
	place = getPlace(names);
	ext = getExt(names);
	int size = place.size();
	vector<picture> pictures(size);
	for(int i=0;i<size;i++)
	{
		pictures[i].city = city[i];
		pictures[i].place = place[i];
		pictures[i].ext = ext[i];
	}
	vector<picture> original =  pictures;
	sort(pictures.begin(),pictures.end());
	
	vector<string> result(size);
	for(int i=0;i<size;i++)//pictures
	{
		for(int j=0;j<size;j++)//original
		{
			if(original[j] == pictures[i])
			{
				result[j] = pictures[i].city+"-"+to_string(i+1)+"-"+pictures[i].place+"."+pictures[i].ext;
				break;
			}
		}
	}
	for(string r: result)
		cout<<r<<'\n';
}


/*
 Rajiv took several pictures of the places he visited of the cities he stayed in last 20 years, and kept all of them in a directory on his computer. He named the pictures in this format :
{city name}-{place name}.{file extension}

He wants to number the picture in alphabetic order of city name, followed with alphabeitc order of place name:


delhi-qutub.png
delhi-redfort.jpg
hyderabad-charminar.jpeg
kolkata-maidan.jpeg
kolkata-museum.png
kolkata-botanicalgarden.jpeg

{city name}-{2 digit number}-{place name}.{file extension}

delhi-01-qutub.png
delhi-02-redfort.jpg
hyderabad-03-charminar.jpeg
kolkata-05maidan.jpeg
kolkata-06-museum.png
kolkata-04-botanicalgarden.jpeg
 * */
