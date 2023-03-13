#include <string>
#include <math.h>

using namespace std;

class FixedPoint
{
	private:
		
		int i10; 
		double d10;
		string i2, d2;
		
		double num10;
		string num2;
		
		void reverse(string &a)
		{	
			int len = a.length();
			char t = '\0';
			
			for (int i=0; i<len/2; i++)
			{
				t = a[i];
				a[i] = a[len-i-1];
				a[len-i-1] = t; 
			}
		}
		
		string calcIPart(int i)
		{
			string r = "";
			char* intStr;

			while (i > 0)
			{
				r += to_string(i % 2);
				i /= 2;
			}
			
			reverse(r);
			
			return r;
		}
		
		string calcDPart(double d, int bit = 8)
		{
			string r = "";
			int c = 0;
			
			while (d != 1 && c < bit)
			{
				d *= 2;
				r += d >= 1 ? "1" : "0"; 
				if (d > 1) d -= 1;
				c++;
			}
			
			return r;
		}
	
	public:
			
		FixedPoint(double num10)
		{
			this->num10 = num10;
			
			double x;
			d10 = modf(this->num10, &x);
			i10 = this->num10 - d10;
			
			i2 = calcIPart(i10);
			d2 = calcDPart(d10);
			
			num2 = i2 + "." + d2;
		}
		
		string getIPart()
		{
			return i2;
		}
		
		string getDPart()
		{
			return d2;
		}		
		
		string getB2()
		{
			return num2;
		}
		
		double getB10()
		{
			return num10;
		}
};
