#include <string>
#include<map>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(const pair<string,int>& a,const pair<string,int>& b){
    return a.second>b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    multimap<int,int> playNumIdx;
    map<string,vector<int>> groupWithGenres;
    map<string,int> playNameNum;

    for(int i=0;i<plays.size();i++){
         if(groupWithGenres.count(genres[i])>0){
             groupWithGenres[genres[i]].push_back(plays[i]);
             sort(groupWithGenres[genres[i]].begin(),groupWithGenres[genres[i]].end(),greater<int>());
         }
        else{
            vector<int> temp;
            temp.push_back(plays[i]);
            groupWithGenres.insert({genres[i],temp});
        }
        //플레이 횟수별로 정렬
        playNumIdx.insert({plays[i],i});
        if(playNameNum.count(genres[i])>0)
            playNameNum[genres[i]]+=plays[i];
        else
            playNameNum.insert({genres[i],plays[i]});
    }

    vector<pair<string,int>> v(playNameNum.begin(),playNameNum.end());
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++){
        //순서대로
        if(groupWithGenres.at(v[i].first).size()>1)
        {
            //2개인 경우
            if(playNumIdx.count(groupWithGenres[v[i].first][0])>1){
                answer.push_back(playNumIdx.find(groupWithGenres[v[i].first][0])->second);
                //지움으로써 두번째꺼를 출력할 수 있음
                //(idx가 작은 순서대로 정렬되어 있기 때문에 같은게 2개 이상이더라도
                // 무조건 첫번째것과 두번째 것만 출력하면 됨)
                playNumIdx.erase(playNumIdx.find(groupWithGenres[v[i].first][0]));
                answer.push_back(playNumIdx.find(groupWithGenres[v[i].first][0])->second);
                playNumIdx.erase(playNumIdx.find(groupWithGenres[v[i].first][0]));
                printf("aaa\n");
            }
            else{
                answer.push_back(playNumIdx.find(groupWithGenres[v[i].first][0])->second);
                answer.push_back(playNumIdx.find(groupWithGenres[v[i].first][1])->second);
            }
            
        }
        else{
            //1개인 경우
            answer.push_back(playNumIdx.find(groupWithGenres[v[i].first][0])->second);
        }
    }
    
    return answer;
}