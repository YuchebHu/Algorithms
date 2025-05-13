#include "quick_union.h"
#include <optional>

class weight_quick_union : public quick_union {
public:
  weight_quick_union(int count) : quick_union(count), tree_size_(count, 1) {}

  virtual void make_union(int p, int q) {
    std::optional<int> p_id = this->find(p);
    std::optional<int> q_id = this->find(q);
    if (!p_id || !q_id) {
      return;
    }
    if (*p_id == *q_id) {
      return;
    }
    const int &p_root = *p_id;
    const int &q_root = *q_id;
    if (this->tree_size_[p_root] > this->tree_size_[q_root]) {
      this->ids_[q_root] = p_root;
      this->tree_size_[p_root] += this->tree_size_[q_root];
    } else {
      this->ids_[p_root] = q_root;
      this->tree_size_[q_root] += this->tree_size_[p_root];
    }
    --this->count_;
  }

private:
  std::vector<int> tree_size_;
};