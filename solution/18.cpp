#include <vector>

using namespace std;


void mapping(vector<int>& hash, const vector<int>& arr, int target )
{
    for(int i = 0; i < arr.size(); i++){
      //??target蹂대떎 ??媛믪? ?댁? ?딆쓬(?듭씠 ??媛?μ꽦???놁쓬)       
        if(arr[i] > target) continue;
        //?룻쁽???먯냼??媛믪쓣 hash???몃뜳?ㅻ줈 ?쒖슜, ?대떦 ?꾩튂??媛믪쓣 1濡??ㅼ젙
        hash[arr[i]] = 1;
    }
}
bool solution(vector<int> arr, int target)
{
   //??target+1媛쒖쓽 怨듦컙???덈뒗 hash踰≫꽣 ?좎뼵
    vector<int> hash(target+1,0);
    
   //?퉍rr???먯냼??媛믪뿉 ??댁꽌 hash table ?앹꽦
    mapping(hash,arr,target);
    
    
    for(int i = 0 ; i < arr.size(); i++)
    {
        
       //??target?먯꽌 arr[i]瑜?類 媛믪씠 ?덈뒗吏 ?뺤씤?섍린 ?꾪빐 num ?좎뼵 
        int num = target - arr[i];
        
      //??arr[i]媛 num怨?媛숈? 寃쎌슦???듭씠 ?좎닔 ?놁쓬(?쒖빟?ы빆??以묐났 ?レ옄媛 議댁옱?섏? ?딆쓬)
        if(arr[i] == num) continue; //以묐났?섎뒗 ?レ옄媛 ?녿뒗?? ?뱀젙媛믪씠 ?꾩옱 ?レ옄媛 媛숈? 寃쎌슦
    
       //???뚯닔??議댁옱?????놁쑝誘濡??듭씠 ?????놁쓬 
        if(num < 0 ) continue; // ?뱀젙媛믪씠 0蹂대떎 ?묒쓣寃쎌슦
       
        //??num???덈떎硫??⑹씠 target???섎뒗 蹂?섎? 李얠?寃껋씠誘濡? true瑜?諛섑솚
        if(hash[num]) return true; // 媛믪쓣 李얠? 寃쎌슦
    }
   //?????섏쓽 ?⑹씠 target???섎뒗 寃쎌슦瑜?李얠? 紐삵븯硫?false 諛섑솚    
    return false;
    
}





//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    //true瑜?異쒕젰?섎㈃ 1?대릺怨?false瑜?異쒕젰?섎㈃ 0
    cout<< solution({1, 2, 3, 4, 8}, 6) << endl; // 1
    cout<< solution({2, 3, 5,9}, 10) << endl; // 0
    return 0;

}
