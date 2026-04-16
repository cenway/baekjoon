unordered_set, unordered_multiset, unordered_map 

값으로 넣고 빼고 하기 쉬운 자료구조
if(tmp2 == "enter") s.insert(tmp1);
else s.erase(tmp1);

s.find() 없으면 end() 반환

최악의 경우
탐색, 삭제는 O(N)이 된다
이름 그대로 정렬이 안 된다
