#include <string>

using namespace std;

bool visited[11][11][4]; // ???뱀젙 醫뚰몴?먯꽌 ?뱀젙 諛⑺뼢?쇰줈 ?대룞???곸씠 ?덈뒗吏 泥댄겕?섎뒗 諛곗뿴

// ???곹븯醫뚯슦濡?醫뚰몴瑜??대룞?????꾩슂??醫뚰몴???ㅽ봽??諛곗뿴 
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// ??媛?臾몄옄???대떦?섎뒗 ?ㅽ봽??諛곗뿴???몃뜳?ㅻ? 諛섑솚
int todir(char dir) {
    int ret;
    if (dir == 'U') ret = 0;
    else if (dir == 'R') ret = 1;
    else if (dir == 'D') ret = 2;
    else ret = 3;
    return ret;
}

// ???뱀젙醫뚰몴媛 二쇱뼱吏?醫뚰몴?됰㈃??踰쀬뼱?섎뒗吏 ?뺤씤
bool isNotValid(int x, int y)
{
    return x < 0 || y < 0 || x > 10 || y > 10;
}
// ???꾩옱? 諛섎? 諛⑺뼢???ㅽ봽??諛곗뿴 ?몃뜳??諛섑솚
int opposite_direction(int dir)
{
    return (dir+2) % 4;
}

int solution(string dirs)
{
    int answer = 0;
    int x = 5, y = 5; // ???쒖옉 醫뚰몴瑜??ㅼ젙

    for (auto c : dirs) {
     // ??諛섎났臾몄쓣 ?쒗쉶?섎ŉ nx, ny?? x, y媛 dirs?濡??吏곸??????꾩튂媛 ??
        int dir = todir(c);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // ??醫뚰몴?됰㈃??踰쀬뼱??寃쎌슦 ???댁긽 ?대룞?섏? ?딆쓬
        if (isNotValid(nx,ny)) {
            continue;
        }

        // ?? ?ㅼ쓬 醫뚰몴媛 ?꾩쭅 諛⑸Ц?섏? ?딆? 醫뚰몴??寃쎌슦
        if(visited[y][x][dir] == false) {
          // ??諛⑸Ц??以묐났 泥댄겕?섏? ?딅룄濡??대떦 寃쎈줈???묐갑?μ쓣 諛⑸Ц 泥댄겕
            visited[y][x][dir] = true;
            visited[ny][nx][opposite_direction(dir)] = true;
            answer++;
        }
      // ???꾩옱醫뚰몴瑜??대룞??醫뚰몴濡??낅뜲?댄듃
        x = nx;
        y = ny;
    }
    return answer;
}




//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iostream>

int main()
{
    cout << solution("ULURRDLLU") << endl; // 7
    cout << solution("LULLLLLLU") << endl; // 7 

    return 0;
}
