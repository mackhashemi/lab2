/** @file Currency.cpp */

Currency::Currency()
{
  // Default constructor
  type = INVALID;  // default type - if none is specificed
  whole = 0;
  fract = 0;
}


Currency::Currency(const e_currency_type in_type,
		   const int in_whole, const int in_fract)
{
  // Parametrized constructor
  // TODO: defend against negative initial values
  type = in_type;
  whole = in_whole;
  fract = in_fract;
}


Currency Currency::operator =(const Currency &right)
{
  this->type = right.type;
  this->whole = right.whole;
  this->fract = right.fract;
  return *this;
}


Currency Currency::operator +(const Currency &right)
{
  /* TODO: handle currency of different type */
  return *this += right;
}


Currency Currency::operator +=(const Currency &right)
{
  /* TODO: handle currency of different type */
  this->whole = this->whole + right.whole;
  this->fract = this->fract + right.fract;

  while (this->fract >= 100)
    {
      this->fract -= 100;
      this->whole += 1;
    };

  return *this;
}


Currency Currency::operator -(const Currency &right)
{
  /* TODO: handle currency of different type */
  return *this -= right;
}


Currency Currency::operator -=(const Currency &right)
{
  /* TODO: handle currency of different type */
  if ((right.whole > this-> whole) ||
      ((right.whole == this->whole) && (right.fract > this->fract))) {
    // subtracting a larger amount - negative is not allowed.  Go to 0
    this->whole = this->fract = 0;
    this->type = INVALID;
  } else {
    this->whole = this->whole - right.whole;
    this->fract = this->fract - right.fract;
  }

  while ((this->fract < 0) && (this->whole > 0))
    {
      this->fract += 100;
      this->whole -= 1;
    };

  return *this;
}


std::ostream& operator << (ostream &output, const Currency &c)
{
  output << currency_name[c.type].symbol
	 << setw(3) << setfill(' ') << c.whole << "."
	 << setw(2) << setfill('0') << c.fract << " -- or "
	 << c.whole << " " << currency_name[c.type].name_whole << " and "
	 << c.fract << " " << currency_name[c.type].name_fract << endl;
  return output;
}


bool Currency::isValid() const
{
  if (this->type == INVALID) {
    return false;
  } else {
    return true;
  }
}

bool Currency::isSameType(const Currency c)
{
  if ((this->type == INVALID) || (c.type == INVALID)) {
    // one or both are not there - no match
    return false;
  }

  if (this->type == c.type) {
    // matches
    return true;
  } else {
    return false;
  }
}
