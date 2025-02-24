class Span
{
private:
	/* Span */
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span&);
	Span&	operator=(const Span&);

	void addNumber();

	~Span();
};
