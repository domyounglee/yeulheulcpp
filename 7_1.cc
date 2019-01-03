#include<iostream>
#include<cstring>
using namespace std;

class Car
{
	private:
		int gasolineGauge;
	public:
		Car(int gas):gasolineGauge(gas){
			
			cout<<"gas"<<this->gasolineGauge<<endl;
		}
		int GetGasGauge(){
			return gasolineGauge;
		}
		~Car(){
			cout<<"byegas"<<endl;
		}
};

class HybridCar:public Car{
	private:
		int electricGauge;
	public:
		HybridCar(int gas, int elec ):Car(gas),electricGauge(elec){
			
			cout<<"HybridCar"<<this->electricGauge<<endl;
		}
		int GetElecGauge(){
			return electricGauge;
		}
		~HybridCar(){

			cout<<"byehybrid"<<endl;
		}
};

class HybridWaterCar:public HybridCar{
	private:	
		int wateGauge;
	public:
		HybridWaterCar(int gas, int elec, int water):HybridCar(gas,elec),wateGauge(water){
			
			cout<<"HybridWaterCar"<<this->wateGauge<<endl;
		}
		void ShowCurrentGauge(){

			cout<<"remain gas"<<GetGasGauge()<<endl;
			cout<<"remain ele"<<GetElecGauge()<<endl;
			cout<<"remanin water"<<wateGauge<<endl;
		}
		~HybridWaterCar(){
			cout<<"byehybridwater"<<endl;
		}
};

int main(void){

	HybridWaterCar HBW(100,200,300);
	HBW.ShowCurrentGauge();


	return 0;
}




