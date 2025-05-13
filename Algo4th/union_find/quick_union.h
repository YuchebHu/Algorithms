#include <optional>
#include <vector>

class quick_union {

public:
  explicit quick_union(int count) : count_(count), ids_(count) {
    for (int i = 0; i < count; ++i) {
      this->ids_[i] = i;
    }
  }

  bool is_connected(int p, int q) const {
    std::optional<int> p_id = this->find(p);
    std::optional<int> q_id = this->find(q);
    if (!p_id || !q_id) {
      return false;
    }
    return *p_id == *q_id;
  }
  std::optional<int> find(int p) const {
    if (p < 0 || p >= this->ids_.size()) {
      return std::nullopt;
    }
    while (p != this->ids_[p]) {
      p = this->ids_[p];
    }
    return p;
  }
  int get_count() const { return this->count_; }
  virtual void make_union(int p, int q) {
    std::optional<int> p_id = this->find(p);
    std::optional<int> q_id = this->find(q);
    if (!p_id || !q_id) {
      return;
    }
    if (*p_id == *q_id) {
      return;
    }
    this->ids_[*p_id] = *q_id;
    --this->count_;
  }

protected:
  int count_;
  std::vector<int> ids_;
};