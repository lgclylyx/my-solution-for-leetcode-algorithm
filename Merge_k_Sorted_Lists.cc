/*
question: Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/


/*

	使用索引优先队列来选出每一次K个值中的最小值，直到所有元素都处理完成，时间复杂度应该为O(nlogk)

template<typename T>
class IndexMaxPQ{
public:
	IndexMaxPQ(int maxN):pqsize(0){
		eles.resize(maxN);
		pq.resize(maxN);
		qp.resize(maxN);
	}

	void insert(int k,const T& t){
		if(contains(k))
			return;
		pqsize++;
		qp[k] = pqsize;
		pq[pqsize] = k;
		eles[k] = t;
		swim(pqsize);
	}
	void change(int k,const T& t){
		if(!contains(k))
			return;
		eles[k] = t;
		swim(qp[k]);
		sink(qp[k]);
	}
	bool contains(int k){
		if(pqsize == 0)
			return false;
		return qp[k] != 0;
	}
	void deleteIndexk(int& k){
		if(!contains(k))
			return;
		int temp = qp[k];
		pq[temp] = pq[pqsize];
		pq[pqsize] = k;
		qp[pq[pqsize]] = 0;
		qp[pq[temp]] = k;
		pqsize--;
		swim(temp);
		sink(temp);
	}
	T max()const{
		return eles[pq[1]];
	}
	int maxIndex()const{
		return pq[1];
	}
	int delMax(){
		if(pqsize==0)
			return 0;
		int temp =pq[1];
		pq[1] = pq[pqsize--];
		sink(1);
		qp[temp] = 0;
		pq[pqsize+1] = 0;
		return temp;
	}
	bool isEmpty()const{
		return pqsize == 0;
	}
	int size()const{
		return pqsize;
	}
private:

	void swim(int k){
		T temp = pq[k];
		while(k > 1 && (eles[pq[k/2]] > eles[temp])){
			pq[k] = pq[k/2];
			qp[pq[k/2]] = k;
			k=k/2;
		}
		pq[k] = temp;
		qp[pq[k]] = k;
	}
	void sink(int k){
		T temp = pq[k];
		while(2*k <= pqsize){
			int j = 2*k;
			if(j < pqsize && eles[pq[j]] > eles[pq[j+1]]) j++;
			if(eles[temp] > eles[pq[j]]){
				pq[k] = pq[j];
				qp[pq[j]] = k;
				k = j;
			}else
				break;
		}
		pq[k] = temp;
		qp[temp] = k;
	}
private:
	vector<T> eles;
	vector<int> pq;
	vector<int> qp;
	int pqsize;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        IndexMaxPQ<int> pq(lists.size()+1);
        ListNode *p = NULL, *s;
        for(int i = 0; i < lists.size(); i++){
            if(NULL != lists[i]){
                pq.insert(i+1,lists[i]->val);
            }
        }
        while(true){
            int i = pq.delMax();
            if(0 == i)
                break;
            if(NULL == p){
                s = p = lists[i-1];
            }else{
                s->next = lists[i-1];
                s = s->next;
            }
            if(NULL != lists[i-1]->next){
                lists[i-1] = lists[i-1]->next;
                pq.insert(i, lists[i-1]->val);
            }
        }
        return p;
    }
};
*/