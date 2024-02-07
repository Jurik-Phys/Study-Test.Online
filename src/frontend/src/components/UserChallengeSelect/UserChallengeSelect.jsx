import style from './UserChallengeSelect.module.css'
import { useNavigate, useParams } from 'react-router-dom'
import { useState, useEffect } from 'react'

const UserChallengeSelect = () => {
  const navigate = useNavigate();
  const [ sectionTitle, setSectionTitle ] = useState(null)
  const { sectionId } = useParams();

  useEffect( () => {
    switch (sectionId){
      case 'safety':
        setSectionTitle("БЖД")
        break

      case 'phys':
        setSectionTitle("Физика")
        break

      case 'math':
        setSectionTitle("Математика")
        break

      case 'cognitive':
        setSectionTitle("Когнитивизм")
        break

      case 'psychoanalysis':
        setSectionTitle("Психоанализ")
        break

      case 'behaviourism':
        setSectionTitle("Бихевиоризм")
        break

      case 'irony':
        setSectionTitle("Ирония")
        break

      case 'satire':
        setSectionTitle("Сатира")
        break

      case 'anekdots':
        setSectionTitle("Анекдоты")
        break

      default:
    }
  }, [sectionId])

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>{sectionTitle}</div>
        <div className={style.text}>
          <div>
            <label className={style.sText}>
              <input type="radio" id="option1" name="options" checked /> Subsection challenge number ONE
            </label>
            <ul>
              <li>
                <label className={style.sText}>
                  Annotation.
                </label> It is the activity of annotating something. She retained a number of copies for further annotation
              </li>
              <li>
                <label className={style.sText}>
                  Count of questions:
                </label> 25
              </li>
              <li>
                <label className={style.sText}>
                Time to pass:
                </label> 45 min
              </li>
            </ul>
          </div>
            <label className={style.sText}>
              <input type="radio" id="option1" name="options" /> Subsection challenge number TWO
            </label>
            <ul>
              <li>
                <label className={style.sText}>
                  Annotation.
                </label> Ivanovo Power Engineering Institute was founded on the basis of Ivanovo-Voznesensk Polytechnic Institute in 1930
              </li>
              <li>
                <label className={style.sText}>
                  Count of questions:
                </label> 35
              </li>
              <li>
                <label className={style.sText}>
                Time to pass:
                </label> 60 min
              </li>
            </ul>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate(-1)} >Back</button>
          <button className={style.flatButton} onClick={ ()=>navigate("/user-passing-test")} >Start testing</button>
        </div>
      </div>
  );
}

export default UserChallengeSelect;
